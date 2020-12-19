import logging
import os
import pathlib
import subprocess
from collections import OrderedDict


class ExampleChecker:

  def __init__(self, problem, source_file, example_dir):
    self.problem = problem
    self.source_file = source_file
    self.example_dir = example_dir
    self.base_dir = os.path.dirname(self.source_file)
    logging.debug(f'base_dir = {self.base_dir}')
    self.executer = os.path.join(self.base_dir, 'execute.out')
    self.result_dir = os.path.join(self.base_dir, 'results', problem)

  def _compile(self) -> bool:
    status = subprocess.call(['g++', '-std=c++17', self.source_file, '-o', self.executer])
    return (status == 0)

  def _execute(self) -> bool:
    target_dir = os.path.join(self.example_dir, self.problem)
    path = pathlib.Path(target_dir)
    os.makedirs(self.result_dir, exist_ok=True)
    succeed = True
    for input_file in path.glob('input*txt'):
      logging.debug(f'Check result for {input_file}.')
      output_filename = os.path.basename(input_file).replace('input', 'output')
      result_filename = os.path.join(self.result_dir, output_filename)
      status = subprocess.call(self.executer,
                               stdin=open(input_file, 'r'),
                               stdout=open(result_filename, 'w'))
      logging.debug(f'Writing output as {result_filename}')
      succeed &= (status == 0)
    return succeed

  def _check(self) -> dict:
    path = pathlib.Path(self.result_dir)
    result_dict = {}
    devnull = open('/dev/null', 'w')
    result_summary = True
    for myoutput in sorted(path.glob('output*txt')):
      print(f'myoutput={myoutput}')
      logging.debug(f'myoutput={myoutput}')
      output_filename = os.path.basename(myoutput)
      answer_output = os.path.join(self.example_dir, self.problem, output_filename)
      diff_line = subprocess.call(['diff', '-u', '--strip-trailing-cr', myoutput, answer_output],
                                  stdout=devnull,
                                  stderr=devnull)
      result_dict[output_filename] = (diff_line == 0)
      result_summary &= result_dict[output_filename]
    logging.debug(f'result dict = {result_dict}')
    logging.debug(f'result summary = {result_summary}')
    print(f'result_summary={result_summary}')
    return result_summary, result_dict

  def run(self) -> dict:
    if not self._compile():
      raise Exception("compile error!")
    if not self._execute():
      raise Exception ("execution error!")
    return self._check()
