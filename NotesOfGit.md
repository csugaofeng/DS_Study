1.git pull --allow-unrelated-histories 
//对于错误fatal: refusing to merge unrelated histories
//原因：github的仓库和本地没有一个共同的commit，所以
//git拒绝提交，认为写错了origin，这时可以使用--allow-unrelated-histories
//进行确定
2.git pull origin master
//遇到无法提交，一般先pull,也就是使用git pull origin master
//这里origin指远程仓库,master当前分支
//将两个不同项目合并
//需要写git pull origin master --allow-unrelated-histories
//如果设置了默认上传分支可以使用
//git pull --allow-unrelated-histories
