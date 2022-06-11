# 備忘録

## 構想
```mermaid
sequenceDiagram
participant 1 as main
participant 2 as CharSeparate
participant 3 as CharArrMerge

Note over 1: 初期文字設定

1->>+2: ポインター、初期文字、分割キー
alt ポインターに分割文字が追加される
2->>2: キーに基づいて文字分割
Note left of 1: 不具合1
  2->>1: voidで返す。
end

Note left of 1: 不具合２

1->>+3: ポインター、差し込み文字、差し込む場所、間に挟む文字
3->>3: 文字生成 
3->>1: 生成文字を返す。
```

## 不具合
1. CharSeparateで分割した配列の０列目が空？？？
2. CharArrMergeで↓のエラーメッセージが出る。  
ISO C++ forbids converting a string constant to 'char*' [-Wwrite-strings]

## 参考URL
[マークダウンでフローチャート](https://qiita.com/yoktave-yoknel/items/b923fe2b9206beab700c)  
[+α](https://shd101wyy.github.io/markdown-preview-enhanced/#/ja-jp/diagrams)