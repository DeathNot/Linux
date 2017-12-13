使用git进行push时，每次需要输入用户名和密码，通过以下方式设置，可以避免每次用户名和密码的输入
```
git config --global credential.helper cache
git config --global credential.helper 'cache --timeout=3600'
```
