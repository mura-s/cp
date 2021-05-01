# README for leet_py

## VSCode で Test/Debug

- 以下を参考に `.vscode/settings.json` へ追記して、コマンドパレットで python の test/debug 実行
  - 結果はサイドバーのテストのビューに表示される

```json
  "python.testing.unittestArgs": [
    "-v",
    "-s",
    "./leetcode/problems/2",
    "-p",
    "test_*.py"
  ]
```
