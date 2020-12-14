import os
import sys

sys.path.append(os.path.realpath(os.path.dirname(__file__) + "/.."))

from src.example_download import ExampleDownload


def test_get_problem_list_size1():
  ed = ExampleDownload(contest='abc184')
  problem_list = ed.get_problem_list()
  assert (len(problem_list) == 6)


def test_get_problem_list_size2():
  ed = ExampleDownload(contest='abc9999')
  problem_list = ed.get_problem_list()
  assert (problem_list is None)


def test_get_example_size1():
  ed = ExampleDownload(contest='abc184')
  inout_pairs = ed.get_examples(problem='a')
  assert (len(inout_pairs) == 3)


def test_get_example_size2():
  ed = ExampleDownload(contest='abc184')
  inout_pairs = ed.get_examples(problem='g')
  assert (inout_pairs is None)


def test_get_example_content1():
  ed = ExampleDownload(contest='abc184')
  inout_pairs = ed.get_examples(problem='a')
  assert (inout_pairs[0].id == 1)


def test_get_example_content2():
  ed = ExampleDownload(contest='abc184')
  inout_pairs = ed.get_examples(problem='a')
  assert (inout_pairs[0].input_data == '1 2\r\n3 4\r\n')


def test_get_example_content3():
  ed = ExampleDownload(contest='abc184')
  inout_pairs = ed.get_examples(problem='a')
  assert (inout_pairs[0].output_data == '-2\r\n')
