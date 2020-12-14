# example_chcker
[Atcoder](https://atcoder.jp/home)のコンテスト問題の解答となるcppファイルを入力とし、問題に付与されているexample入力に対して正しい答えが出力されるかをチェックするpythonツールである。

# 使い方

clone
```
git clone https://github.com/sarcastic555/atcoder_library.git
export DEVELOP_PATH="${PWD}"
```

docker環境に入る
```
cd atcoder_library/example_checker/docker
source docker_build.sh
source docker_run.sh
```

コンテストのexampleのダウンロード
```
python3 write_examples.py --contest='abc184' --outdir ./examples # ABC184の場合
```

作成した`./test.cpp`に対してexampleを入力した時の出力が正しいかのチェック
```
python checker.py --source_file ./test.cpp --problem a --example_dir ./examples # 問題Aの場合
```

出力（全て正しい出力の場合）
```
INFO:root:output1.txt: OK
INFO:root:output2.txt: OK
INFO:root:output3.txt: OK
INFO:root:******** summary: OK ********
```
