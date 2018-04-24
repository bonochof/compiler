=begin
  識別子判定プログラム
  compiler.c
  7061-0503 Ryosuke Takata
=end

# 判定用定数(識別子なら1)
EMPTY = 0
ID = "識別子"

# 各種変数
str = ""
token = ""
tokens = []
judges = []

# 区切り文字判定
def isseparater?(ch)
  return true if ch.match(/\s|\W/) and ch != '#' and ch != '\\'
  return false
end

# ファイル入力
File.open('./test.c', 'r') do |file|
  str = file.read
end

# トークン分割・識別子判定ループ
state = EMPTY
count = 0
str.each_char do |ch|
  # トークン文字数カウント
  count += 1

  # トークン文字列
  token.concat(ch)

  # 最初の文字が英字の場合，識別子判定
  if count == 1 and ch.match(/[a-z]/)
    state = ID
  end

  # 区切り文字の場合，分割して追加する
  if isseparater?(ch)
    tokens << token #.partition(/\s|\W/)
    judges << state
#    judges << EMPTY if count != 1
    # トークン初期化
    token = ""
    count = 0
    # 識別子判定初期化
    state = EMPTY
  end
end

# 整形
#tokens.flatten!.delete("")
#tokens.each_with_index do |token, i|
#  token
#end

# 表示
tokens.each_with_index do |token, i|
  print token, "\t", judges[i], "\n"
end

