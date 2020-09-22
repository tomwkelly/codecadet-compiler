
# 1 branch 2 token

echo 'Branch:'
echo $1

m=$(curl \
  -X GET \
  -H "Accept: application/vnd.github.v3+json" -s \
-H "Authorization: token ${2}" \
  https://api.github.com/repos/tomwkelly/codecadet-compiler/commits/${1} |  grep -o '"message": "[^"]*' | grep -o '[^"]*$')

echo "message is: $m"

n=$(curl -X POST -s -H "Accept: application/vnd.github.v3+json" -H "Authorization: token ${2}" https://api.github.com/repos/tomwkelly/codecadet-compiler/pulls -d "{\"title\":\"${m}\",\"head\":\"${1}\",\"base\":\"master\"}" | grep -o '"number": [^,]*' | grep -o '[0-9]\d*')

echo "number is: $n"

http_code=$(curl -X PUT -H "Accept: application/vnd.github.v3+json" -H "Authorization: token ${2}" https://api.github.com/repos/tomwkelly/codecadet-compiler/pulls/$n/merge -d "{\"commit_title\":\"Merge ${1} into master\"}" -s -w %{response_code} -o /dev/null )

retrycount=0

echo $http_code

echo $2

while ((($http_code == 404 || $http_code == 000 || $http_code == 404000) && $retrycount < 6))
do
  echo "${http_code} retrying, attempt: ${retrycount}"
  sleep 5s
  ((retrycount += 1))
  http_code=$(curl -X PUT -H "Accept: application/vnd.github.v3+json" -H "Authorization: token ${2}" https://api.github.com/repos/tomwkelly/codecadet-compiler/pulls/$n/merge -d "{\"commit_title\":\"Merge ${1} into master\"}" -s -w %{response_code} -o /dev/null )
done
