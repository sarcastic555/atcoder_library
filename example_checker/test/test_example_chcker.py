import os
import sys

sys.path.append(os.path.realpath(os.path.dirname(__file__) + "/.."))

from src.example_checker import ExampleChecker


def test_compile1():
  source_code = os.path.join(os.path.dirname(__file__), 'data', 'sample.cpp')
  example_dir = os.path.join(os.path.dirname(__file__), 'data', 'examples')
  ec = ExampleChecker(problem='a', source_file=source_code, example_dir=example_dir)
  success = ec._compile()
  assert (success)


def test_compile2():
  source_code = os.path.join(os.path.dirname(__file__), 'data', 'fail.cpp')
  example_dir = os.path.join(os.path.dirname(__file__), 'data', 'examples')
  ec = ExampleChecker(problem='a', source_file=source_code, example_dir=example_dir)
  success = ec._compile()
  assert (not success)


def test_execute():
  source_code = os.path.join(os.path.dirname(__file__), 'data', 'abc184a.cpp')
  example_dir = os.path.join(os.path.dirname(__file__), 'data', 'examples')
  ec = ExampleChecker(problem='a', source_file=source_code, example_dir=example_dir)
  ec._compile()
  success = ec._execute()
  assert (success)


def test_check1():
  source_code = os.path.join(os.path.dirname(__file__), 'data', 'abc184a.cpp')
  example_dir = os.path.join(os.path.dirname(__file__), 'data', 'examples')
  ec = ExampleChecker(problem='a', source_file=source_code, example_dir=example_dir)
  ec._compile()
  ec._execute()
  success, result_dict = ec._check()
  assert (success)


def test_check2():
  source_code = os.path.join(os.path.dirname(__file__), 'data', 'abc184a_fail.cpp')
  example_dir = os.path.join(os.path.dirname(__file__), 'data', 'examples')
  ec = ExampleChecker(problem='a', source_file=source_code, example_dir=example_dir)
  ec._compile()
  ec._execute()
  success, result_dict = ec._check()
  assert (not success)
