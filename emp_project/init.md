 1. 详细设计
    需求分析 模块 ，功能
    数据库设计
    详细设计 流程图伪代码
    编码
        a. 准备环境
        b. 真是编码

    测试
    部署

2. 技术选型
    前端:vue + axios
    后端: springboot+mybatis + mysql + tomcat + redis

3. 需求分析
    a.用户登录
    b.用户注册
    c.验证码
    d.欢迎页面
    e.员工列表
    f.安全退出
    g.员工添加
    h.员工的修改
    i.员工列表加入Redis缓存

4. 库表设计

    用户表
    员工表
    ```sql

    create table t_user(
        id int primary key auto_increment,
        username varchar(20),
        realname varchar(20),
        password varchar(20),
        sex varchar(4),
        status varchar(4),
        registerTime timestamp
    );

    create table emp_user(
        id int primary key auto_increment,
        name varchar(20),
        path varchar(256),
        salary double(10,2),
        age int(3)
    );
    ```
     表入库

4. 编码环节
    a.环境搭建
    springboot + mybatis + myslq 引入员工管理界面

    项目名称:ems_vue
    项目中的包
        /src/main/java
            com.gtj.xxx
                    .util
                    .dao
                    .service
                    .....
        /src/main/resource
            application.yml(properties) springboot配置文件
            application-dev.yml 测试
            application-prod.yml 生产配置
            com/gtj/mapper  mybatis的配置文件
            com/gtj/sql     存放项目中的sql文件
            static          存放静态资源
























