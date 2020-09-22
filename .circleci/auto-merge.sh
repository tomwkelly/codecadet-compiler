
# 1 branch 2 token

echo 'Branch:'
echo $1

m=$(curl \
  -X GET \
  -H "Accept: application/vnd.github.v3+json" \
-H "Authorization: token ${2}" \
  https://api.github.com/repos/tomwkelly/codecadet-compiler/commits/${1} |  grep -o '"message": "[^"]*' | grep -o '[^"]*$')

n=$(curl \
  -X POST \
  -H "Accept: application/vnd.github.v3+json" \
-H "Authorization: token ${2}"  https://api.github.com/repos/tomwkelly/codecadet-compiler/pulls \
  -d "{\"title\":\"${m}\",\"head\":\"${1}\",\"base\":\"master\"}" | grep '"number": [^,]*' | grep -o '[0-9]\d*')

curl \
  -X PUT \
  -H "Accept: application/vnd.github.v3+json" \
-H "Authorization: token ${2}" \
  https://api.github.com/repos/tomwkelly/codecadet-compiler/pulls/$n/merge \
  -d "{\"commit_title\":\"Merge ${1} into master\"}"
