import argparse
import logging

from src.example_checker import ExampleChecker


def options():
  parser = argparse.ArgumentParser()
  parser.add_argument('--source_file', help='Path to source code file.', required=True)
  parser.add_argument('--problem', help='Problem ID', required=True)
  parser.add_argument('--example_dir', help='Path to example data directory.', required=True)
  args = parser.parse_args()
  logging.debug(f'options={args}')
  return args


def convert_result_message(result: bool) -> str:
  return 'OK' if result else 'NG'


def main(options: argparse) -> None:
  checker = ExampleChecker(problem=options.problem,
                           source_file=options.source_file,
                           example_dir=options.example_dir)
  result_summary, result_dict = checker.run()
  for example, result in result_dict.items():
    logging.info(f'{example}: {convert_result_message(result)}')
  logging.info(f"******** summary: {convert_result_message(result_summary)} ********")


if __name__ == '__main__':
  logging.basicConfig(level=logging.INFO)
  options = options()
  main(options=options)
