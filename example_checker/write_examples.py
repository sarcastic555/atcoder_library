import argparse
import logging
import os
import shutil
import sys

from src.example_download import ExampleDownload


def options():
  parser = argparse.ArgumentParser()
  parser.add_argument('--contest', help='Contest name', required=True)
  parser.add_argument('--outdir', help='Example output directory', default='examples')
  args = parser.parse_args()
  logging.debug(f'contest name = {args.contest}')
  return args


def main(options: argparse) -> None:
  downloader = ExampleDownload(contest=options.contest)
  problems = downloader.get_problem_list()
  if os.path.exists(options.outdir):
    shutil.rmtree(options.outdir)
  for problem in problems:
    examples = downloader.get_examples(problem=problem)
    for example in examples:
      output_dir = os.path.join(options.outdir, problem)
      os.makedirs(output_dir, exist_ok=True)
      filename_in = os.path.join(output_dir, f'input{example.id}.txt')
      filename_out = os.path.join(output_dir, f'output{example.id}.txt')
      with open(filename_in, mode='w') as f:
        f.write(example.input_data)
        logging.debug(f'Generating {filename_in}')
      with open(filename_out, mode='w') as f:
        f.write(example.output_data)
        logging.debug(f'Generating {filename_out}')


if __name__ == '__main__':
  logging.basicConfig(level=logging.INFO)
  options = options()
  main(options=options)
