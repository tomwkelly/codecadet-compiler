


n=$(curl \
  -X POST \
  -H "Accept: application/vnd.github.v3+json" \
-H "Authorization: token ${2}"  https://api.github.com/repos/tomwkelly/codecadet-compiler/pulls \
  -d '{"title":"${1}","head":"crme","base":"master"}' | grep '"number": [^,]*' | grep -o '[0-9]\d*')

curl \
  -X PUT \
  -H "Accept: application/vnd.github.v3+json" \
-H "Authorization: token ${2}" \
  https://api.github.com/repos/tomwkelly/codecadet-compiler/pulls/$n/merge \
  -d '{"commit_title":"commit_title"}'
