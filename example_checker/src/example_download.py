import copy
import dataclasses
import logging
import time
from typing import List, Tuple

import bs4
import requests


@dataclasses.dataclass
class ExampleData:
  id: int
  input_data: str
  output_data: str


class ExampleDownload:

  def __init__(self, contest: str) -> None:
    logging.debug(f'contest={contest}')
    self.contest = contest
    self.base_url = f'https://atcoder.jp/contests/{self.contest}/tasks'
    self.sleep = 1  # [sec]

  def get_problem_list(self) -> List[str]:
    time.sleep(self.sleep)
    r = requests.get(self.base_url)
    if not r.ok:
      return None
    soup = bs4.BeautifulSoup(r.text, 'html.parser')
    problems = soup.find(class_='table table-bordered table-striped').find('tbody').find_all('tr')
    problem_list = []
    for problem in problems:
      title = problem.find('td').text
      if len(title) == 1 & title.isupper():
        # change to lower letter because it is used as lower letter in URL
        title = str.lower(title)
        problem_list.append(title)
    return problem_list

  def get_examples(self, problem: str) -> List[ExampleData]:
    problem_url = f'{self.base_url}/{self.contest}_{problem}'
    logging.debug(f'Problem URL = {problem_url}')
    time.sleep(self.sleep)
    r = requests.get(problem_url)
    if not r.ok:
      logging.error(f'Cannot get {problem_url}')
      return None
    statement = bs4.BeautifulSoup(r.text, 'html.parser').find(id='task-statement')
    # Recent contests have "part" class, while old contests (ex. ARC-050) have "section" tag.
    # Try to handle both cases.
    parts = statement.find_all(class_='part')
    if len(parts) == 0:
      parts = statement.find_all('section')
    logging.debug('parts size = %d' % len(parts))
    inout_pairs = []
    ret = ExampleData(-1, None, None)
    for part in parts:
      title = part.find('h3').text
      if title.startswith('入力例'):
        # Recent contests have "入力例 1" format, while old contests (ex. ARC-050) have "入力例1" format.
        # Try to handle both cases.
        problem_id = title.replace('入力例 ', '').replace('入力例', '')
        ret.id = int(problem_id)
        # Remove initial space and new line code
        ret.input_data = part.find('pre').text.lstrip()
        logging.debug(f'input data ={ret.input_data}')
      elif title.startswith('出力例'):
        # Remove initial space and new line code
        ret.output_data = part.find('pre').text.lstrip()
        logging.debug(f'output data ={ret.output_data}')
        if ret.input_data is not None and ret.output_data is not None:
          # Need to be appended using copy.copy, otherwise it will be overwritten
          inout_pairs.append(copy.copy(ret))
          ret.input_data = None
          ret.output_data = None
    logging.debug('example size = %d' % len(inout_pairs))
    return inout_pairs
