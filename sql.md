# 数据库

## 数据库操作笔记

| 名称 | 含义   |
|---|---|
| DDL|数据定义语言（Data Definition Language）DDL用来创建数据库中的各种对象，创建、删除、修改表的结构 比如表、视图、索引、同义词、聚簇等。其主要功能是定义数据库对象，核心指令为create、drop、alter |
| DML |数据操作语言（Data Manipulation Language） 对数据库表中的数据进行增删改,DML的核心指令为insert、update、delete  (删除一条或按条件匹配)|
| DQL| 数据查询语言（Data Query Language）用来查询数据库表中的记录,DQL的核心指令为select。通常与关键字from、where、group by、having、order by等一起使用，组成查询语句|
| DCL| 数据库控制语言（Database Control Language）用来授予或回收访问数据库的某种特权，并控制数据库操纵事务发生的时间及效果，对数据库实行监视等|
| TCL |事务控制语言（Transaction Control Language）简称TCL。用于管理数据库中的事务。这些用于管理由 DML 语句所做的更改。它还允许将语句分组为逻辑事务 TCL经常被用于快速原型开发、脚本编程、GUI和测试等方面。TCL的核心指令为commit、rollback。|

### DDL(数据定义语言)

|  操作 |  定义 |
|---|---|
| 查看所有数据库| show databases;|
| 查看所有表| show tables;|
| 删除数据库| drop database dbname;|
| 创建数据库| create database dbname;|
| 选择数据库| use database;|
| 创建表| create table tanem(id int,name varchar(20));|
| 查看表结构| desc tname|
| 插入数据| insert into tname values(3,张三);|
| 修改表结构(add添加列)| alter table tname add(age,int);|
| 修改表结构(drop删除列)| alter table tname drop id;|
| ...(modify修改字段类型)| alter table tname modify age varchar();|
| ...(change修改字段名称)| alter table tanme change age plage int(3);|
| ...(rname修改表名称)| alter table tname rname newtnmae;|
| ...(truncate清空表结构)| truncate table tname;|
| 删除表| drop table t1;|

### DML(数据操纵语言)

insert
delete
update
where

当值为null的时候只能使用，is 或者 not is 而不能用 =，！= ,(相当于=)
等等  

出自唐代黄巢的《不第后赋菊》
待到秋来九月八，我花开时彼花杀。
冲天香阵透长安，满城尽带黄金甲。  

### TCL(事务控制语言)

|  操作 | 命令  |
|---|---|
| 提交| commit |
| 撤回| rollback |
| 保存点| savepoint |
只有当存储引擎为innodb的时候才有事务的功能,MySQL 默认的Myisam不支持事务
事务的验证: start trancaction(交易) 第二步:savepoint 保存点名称 第三步: DML 第四步:commit/rallback

### DQL(数据查询语言)

asc (正序)

### DCL(数据库控制语言)

|  操作 | 命令  |
|---|---|
| 创建用户| create user username@ip identified by password |
| 查看用户的所有权限| show grants for username@ip |
| 授权| grant 权限名称(多个之间以空格隔开) on 数据库名称 to username@ip; |
| 撤销权限| revoke 权限名称(list) on 数据名称 from username@ip; |

### 多表操作

|  连接方式 | 解释 |
|---|---|
| 等值连接 |两张表有相同的字段,把两张表连接起来,这时候两张表就相当于是一张表,有的字段没有值的,用null表示。 |
| 笛卡尔积 |用一张表的每一条记录都与另一张表的所有记录进行组合，比如A表有x条数据，B有y条数据，笛卡尔积有x*y条结果，通常没有实际意义 |
| 内连接 |使用join on 就是内连接，效果与等值连接相同 |
| 外连接 |在多表查询的时候除了显示满足条件的数据，还要显示不满足条件的数据 |
1.驱动表（主表）除了显示满足条件的数据，还需显示不满足条件的数据
2.从表（附表）只显示满足条件的数据
3.外连接分为三种 inner join（只差左右两边相等的行的数据），left join（左边的表要查出全部数据，右边的的表数据只用查出有与左边表相等的信息），right join（道理与left join相似）

### 数据的导出导入

|  方式 | 解释 |
|---|---|
| 数据的导出| mysqldump -h ip -u username -p password -d dbname(-all-databases 导出所有数据库的数据) 导出的文件名称 |
| 数据的导入| (导入数据库之前要先创建数据库)mysql -h ip -u username -p passwd -d dbname(如果是全部数据库的话可以不写数据库名称)  要导入数据的文件名称 |

### 数据类型需要注意的地方

* int() 后面的括号时不可以控制精度的括号只是表示 select 选出来之后结果集中的宽度,不影响实际的取值范围, 实际使用配合zerofill，没有的位数按0补足
* 整数 tinyint(8位),smallint(16位),mediumint(24位),int(32),bigint(64位)
* 定义表的时候直接声明 engine=innodb(引擎) charset=utf-8(字符集)

### 浮点型

* float(m,n) 表示全部位数,n表示小数位数
* float 4个字节 double 8个字节

### 定点型(主要用于互联网金融)

* 浮点数存放在数据库是近似值,定点型放在数据库是精确值
* decimal(m,n)参数 m65 表示总个数,d<30 d<60 是小数位
* 定点数据类型是deicmal数据类型
* decimal类型的默认长度是decimal(10,0)

### 字符串

|  方式 | 解释 |
|---|---|
| char(m)| 定长,最多255个,mysql 会将char最后的空格给忽略(存储时用空格填充)而varchar不会 |
| varchar(m)| 可变,最多65535个字节,char的速度比varchar更快 |
| tinytext| 可变长度,最多255个字节 |
| text| 可变长度,最多65535个字节 |
| mediumtext| 可变长度最多2的24次方减一字节 |
| longtext| 可变长度最多2的32次方减一字节 |

* 在不同的编码下面最大保存的字符数量是不同的  
对于未指定varchar 字段是否为null的表会有一个字节用来表示当前表是否为null
对于varchar(n) n255 的时候会有一个字节专门表示字符串的长度,当n255 的时候会有两个字节来代表字符串的长度
所有英文的长度都是一,但是其他字符串编码的每个字符占用的字节书不一定是一
所有varchar 长度255 转换成tinytext
所有varchar 长度500 转换成text
所有varchar 长度20000 转换成medium
varchr 可以指定n text不能指定n,varchar内部存储的字符是实际减1或2,text是实际的减去2
* varchar和text的区别
varchar 可以使用长度限制,text不能
varchar 可以直接创建索引,而text创建索引要指定长度,varchar的速度快于text ,都在创建索引的情况下,text的索引似乎不起作用
MySQL的单行最大数据量是64KB,当varchar大于某些数值的时候,varchar 会自动转换成text(存储效率高)
text 不允许有默认值,而varchar可以
varchar和text两种数据相比,建议是能用varchar就用varchar

### 日期时间类型

| 数据类型 |字节数 |格式 |备注|
|---|---|---|---|
| data | 3| yyyy-MM-dd|存储日期 |
| time| 3| HH:mm:ss| 存储时分秒 |
| year| 1| yyy| 存储年 |
| datatime| 8| yyyy-MM-dd HH:mm:ss|日期加时分秒(非unix时间) |
| timestamp|4|yyyy-MM-dd HH:mm:ss|日期加时分秒,时间戳(unix需要时区)

### 枚举类型

enmu(里面放枚举列表)
desc可以查看到用了那些类型的数据

### 数据类型的约束

|  方式 | 解释 |
|---|---|
| null | 数据可以包含NULL |
| not null| 数据不可以包含NUL |
| default|默认值 |
| primary key|主键 |
| auto_increment|自动递增 |
| unsigned|无符号 |
| character_set name|指定一个符号集 |

### 索引

| index| | 普通索引:所应列表可以重复 |
| unique|索引列必须是唯一,可以为null |
| primary key|索引列必须唯一,不可以为空,一张表只能有一个主键索引 |
| full text|每个字段创建一个索引 |

* 不同的所应之间的作用区别

  * 普通索引常用于过滤数据 列如,以商品种类为索引,检索手机类的商品
  * 唯一索引的主要用途是标识一列数据不要重复,相比主键索引不常用在检索场景
  * 主键索引是唯一的标识,因而其主要作用是检索特定数据
  * 全文索引的效率比较低,常用于文本的内容

#### MySQL使用索引

```sql
#查看索引用 show index from tname;
##创建普通索引

#1. 在创建表时侯创建索引

create table tname(
id int not null,
name varchar(20)
index indexname(columnName(typenumber)) 
);
#2.在现有的表上面进行修改
altert table tname add index indexname(columName(typenumber));
create index indexname on tname columeName(typenumber);

##创建唯一索引
#1. 创建表的时候指定
create table tname(
id int not null,
name varchar(20)
unique indexname(columnName(typenumber)) 
);

#2.基于现有表创建
create unique index uniquename on tname(columeNmae) 

##创建主键索引
#1.创建的时候指定
create table tname(
id int primary key,
name varchar(20)
);

#2.基于现有表修改
alter table tname add primary key (column);
show index from tname;
#查看索引
```

* 使用索引的条件
  * 常用于条件查询的字段,where like join等等
  * 唯一性太差的字段不能用来做索引
  * 更新太过于频繁的字段
  * 对小的表没有意义添加索引(小的表本来就很快)
  * 索引可以直接获取索引所在行

### MySQL权限控制

* 数据库和表的格式

| 格式 | 解释 |
| --- | --- |
| 数据库名称.\* | 数据库中所有的表 |
| 数据库名称.表名称| 指定数据库中的表 |
| 数据库名称.存储过程名|指定数据库中的存储过程 |
| \*.\* | 全部的数据库中的全部表 |

* 用户和ip格式

| 格式 | 解释 |
| --- | --- |
| 用户名@ip地址| 用户只能在此IP下才能访问 |
| 用户名@192.168.1.%| 用户只能在此网段下才能访问 |
| 用户名@%.xxx.com| 用户只能在此为此域名结尾下才能访问 |
| 用户名@%| 任何IP下都能访问 |

| 格式 | 解释 |
| --- | --- |
| 创建用户| create user 'username'@ip identified by 'password'; |
| 赋给用户权限| grant permissionname on dbname to username@ip identified by 'password'; |
| 删除用户 | drop user username@ip; |
| 移除权限| revoke permissionname on dbname from username@ip; |
| 重命名用户 | rename user Oldusername@ip to Newusername@ip |
| 修改密码| mysqladmin -uroot -p oldpassword  newpassword(在命令行执行) |

``` sql
alter user username@ip identified by  Newpassword;(后面两个在mysql 里面执行)
set PASSWORD=password('newpassword');
(root修改其他用户的密码) grant privilegeName on dbname to username@ip identified by 'Newpassword'
(普通用户修改自己的密码) set PASSWORD=password('newpassword');
```

* mysql忘记密码

* 在/etc/my.conf里面添加 skip-grant-tables
* 重启mysql
* 在shell 里面用mysql命令直接登录mysql
* flush privileges;刷新权限不然无法修改
* alter user 'root'@'localhost' identified by '新密码';
* 退出mysql,把/etc/my.conf修改成原来的样子
* 重启mysql 新密码已经设置成功了! 😊吧😁

### 错误日志

默认在安装时候在本机存放日志的地方 如果在数据库里面用 select @@log_error 输出是 stdout 说明没有配置默认的mysql 错误日志 可在mysql的主配置文件中添加 一行 log_error=错误日志要指定的文件 重启服务器就成功了

### 二进制日志(除了select 操作不进行备份其他的操作都要进行备份)

server_id=1
log_bin=/data/3306/binlog/mysql-bin( log_bin 打开二进制日志的功能, /data/3306/binlog 存放日志文件的文件夹, mysql-bin日志文件的前缀,注意不是日志文件名,mysql每次重启都要创建新的日志文件名称)

server_id 给日志进行标，在集群里面所有的机子都必须相同
此文件比较大 如果要把它放置在空间比较宽裕的地方，而且要把文件相应的权限给到MySQL

DML语言有三种记录模式(操作数据库的数据了)

* SBR--statement 记录做了什么 记录sql语句
* RBR--row 记录数据行的变化(默认模式,推荐)
* MBR-- 自动判断记录模式
* 查看记录模式 select @@binlog_format;
* 查看binlog 相关的记录 show varibles like '%log_bin%'
* 查看当前有哪些二进制日志 show binary logs;
* 查看当前正在使用的日志 show master status;
* 查看日志详细信息 mysqlbinlog 日志文件
* 查看日志里面的内容 show binlog events in'mysql-bin.00001';
* 截取日志 mysqlbinlog --start-position=开始的pos --end-position=结束的pos  日志文件 aaa.sql
* 临时关闭binlog set sql_bin_log=0;

数据恢复实例

* 删除数据后

* set sql_bin_log=0;(暂时关闭二进制日志,避免重复记录)
source 二进制日志存在的位置(相当一执行了)
set sql_bin_log=1;

GTID 二进制数据恢复
| 操作  |  命令 |
|---|---|
| gtid 简介| 1.全局唯一的事务编号 2.幂等性 3.gtid包含两部分 Server_uuid  tx_id |
| 修改书库配置文件打开gtid| gtid_mode=on |
| 配置文件强制开启gtid一致性| enforce_gtid_consistency=true |
| 配置文件开启主从复制,从库保持主库一致| log_slave_updates=1|
| 查看gtid相关属性|  show varibles like '%gtid%' |
| 创建数据恢复介质sql文件 使用gtid 方式 | show binlog events in 'mysql-bin.000002' (查看gtid事务的uuid) mysqlbinlog --skip-gtid  --include-gtid='查询到的uuid :事务编号的范围'  binlog文件存放的位置  sql文件 |

|  参数 |  含义 |
|---|---|
|  --exclude-gtid |  排除 |
| --include-gtid | 包含 |
| --ship-gtid| 跳过|

#### 慢日志(执行比较慢的日志)

|  参数 |  含义 |
|---|---|
| 查看慢日志 相关|show veriables like '%slow_query';|
| 查看慢日志记录的阈值 | select @@long_query_time;|

* 修改配置文件

```bash
slow_query_log=1
slow-query_log_file=/data/3306/data/qfedu-slow.log
long_query_time=1 -- 默认配置10分钟
log_queries_not_using_indexs=1
```

### MySQL备份类型

#### 物理备份

* 热备份
在线备份数据库处于运行状态，这种备份方式依赖于数据库日志文件
对应用基本无影响(应用程序读写不会阻塞,但是性能会有所下降,尽量不要在主库上面做备份,主要在从库上面做)
* 冷备份
将数据库停机做备份
备份数据库datadir下面所有的文件
* 温备份
针对myisam的备份(myisam不支持热备份),备份时候实例只能读不能写,数据库锁定表格的状态下进行
对应用程序影响很大
通常加一个读锁

#### 逻辑备份

对数据库逻辑组件(如表等数据库对象) 的备份,表示为逻辑数据库结构create database 和insert 语句分割文本的信息,这种数据可以用于编辑数据比较小的结构

#### 逻辑备份和物理备份的区别

| - | 逻辑备份  |  物理备份  |
|--- |---|---|
| 备份方式 | 备份数据库逻辑内容  | 备份物理文件  |
| 优点 | 备份文件小,只备份表中的数据与结构 | 恢复速度比较快 |
| 缺点 | 速度慢 | 备份文件较大(数据,索引,碎片) |
|代表工具 | mysqldump| ibbackup,xtrabackup,mysqlbackup |
超过10g 查不多就用物理备份,低于使用逻辑备份

#### MySQL备份策略

* 完全备份
保存的是备份完成时刻的数据库,是差异备份与增量备份的基础
* 差异备份
备份那些自从上次完全备份后被修改过的文件,备份的时间起点是从上次完全备份起,备份数量会越来越大,数据恢复时,只需恢复上次的完全备份和最近一次的差异备份
* 增量备份
只有那些在上次完全备份或增量备份后被修改的文件才会被备份,以上次完全备份或上次增量备份时间为时间起点,只备份做了修改的数据,恢复时要使用上次完全备份的数据和之后的若干次增量备份的数据,如果增量数据损坏将导致数据丢失

### 完整备份与恢复

#### 备份

* 修改配置文件

```bash
[mysql]
basedir=/soft/mysql
datadir=/soft/myslq/data
defualt_password_lifetime=0
server-id=2
bin-log=/var/log/mysql/bin-log
```

* 创建存放二进制日志文件的目录并赋予权限

```bash
mkdir -p /var/log/mysql
chown -R mysql:mysql /var/log/mysql
```

* 创建全备份文件并存放目录并赋予权限

```bash
mkdir /backup/mysql -p
chown -R mysql:mysql /backup/mysql
```
  
* 重启数据库  
* 创建数据库  
* 进行全量备份

```sql
myslqdump -uroot -hlocalhost -p'password' -p3306 --all-databases --triggers --routines --events --single-transaction --master-data=1 --flush-logs --set-gtid-purged=OFF > /backup/mysql/$(data +%F%H)-mysql-all.sql
```

* 删除相关数据库文件(一般在/var/lib/mysql)
删除了这些文件再次启动数据库就会进行初始化操作

#### 还原

* 像全量备份文件中追加不记录二进制日志的命令(还原就是写入命令,还要重复写一次二进制日志造成性能压力)

```bash
sed -i '23a SET sql_log_bin=0;' +日志文件名称 
# 23a 表示23 行
```

* 重启初始化数据库,启动数据库,修改密码

```bash
systemctl restart mysqld
mysql -uroot -hlocalhost -p
grep 'temporay password ' /var/log/mysql.log
mysql -u root -p'passwd'

mysql>alter user username@ip identified by "newpassword";
```

* 还原数据库
mysql -uroot -hlocalhost -p'passwoed' < 存放数据库备份文件的位置

### 增量备份与恢复

增量备份直接用之前的二进制日志文件，还要之前全量备份的position

1.先把全量备份恢复了
2.再恢复增量备份的数据

```sql
mysqlbinlog  --start-position=154 /var/log/mysql/bin-log.000005 /var/log/mysql/bin-log.000006 | mysql -uroot -p'password'
```

### MySQL 主从复制

1. 常见的应用场景

* 读写分离，提高
* 实时灾备，一个数据库坏了即使切换到另外一个数据库
* 数据汇总，将多个数据库的数据存放到一个数据库，方便数据统计
  
2. mysql主从复制原理介绍

* 异步和半同步介绍（mysql默认的是异步复制）
异步时主节点执行和提交事务,然后将它们异步的发送给从节点,已重新执行和或者应用.(从数据库数据会延迟)
半同步时先把操作先发送给从数据库,再把commmit动作执行之后在在主数据库提交(降低主数据库的io能力)

3. mysql主从复制过程

* 开启binlog,通过把数据库的binlog从主库传到从库,重新应用解析
* 复制主库需要三个线程(dump,io,sql) 完成
* 复制是异步的过程,主从复制的异步复制的本质是逻辑复制

----
MySQL主从复制前提

1. 主服务器一定要打开二进制日志
2. 必须要两台服务器
3. 从服务器需要一次数据初始化
4. 如果主从都是新搭建的不用初始化
5. 如果主数据库是运行很久的,可以使用备份将主数据库的数据复制到从数据库
6. 主数据库必须要有对从库复制请求的用户
7. 从库要有relay-log设置,存放从主库传过来的二进制日志 show variable like ''%relay-log%
8. 在第一次的时候,从库要change master to 去连接主数据库,提供了连接用户的user,password,port,ip
9. change master信息要放到master.info 中 show variables like '%master_info%'
10. 从库怎能知道,主库发生了新的变化,通过relay-log.info 记录已经应用过的relay-log信息
11. 在复制过程中涉及到的线程
  io线程负责连接主库,请求binlog ,接收binlog 并且写入relay-log
  sql线程负责执行relay-log中的事件
  dump负责相应io线程的请求

4. 编辑配置文件

主配置文件

```bash
datadir=/var/lib/mysql
socket=/run/mysqld/mysqld.sock

default-storage-engine=INNODB #默认引擎
symbolic-links=0
server_id=6 # 服务id，两个服务id不能一样
sql_mode=NO_ENGINE_SUBSTITUTION,STRICT_TRANS_TABLES
log_error=/var/log/mysql.log # 错误日志
log_bin=/var/log/mysql/mysql-bin # 开启二进制日志,注意要创建文件夹以及要修改权限
```

从库配置文件

```bash
datadir=/var/lib/mysql
socket=/run/mysqld/mysqld.sock

default-storage-engine=INNODB #默认引擎
symbolic-links=0
server_id=5 # 服务id，两个服务id不能一样
sql_mode=NO_ENGINE_SUBSTITUTION,STRICT_TRANS_TABLES
log_error=/var/log/mysql.log # 错误日志
log_bin=/var/log/mysql/mysql-bin # 开启二进制日志 ,注意要创建文件夹以及要修改权限
```

从库准备操作

```sql
MariaDB [(none)]> create user slave@'%' identified by '13333';
Query OK, 0 rows affected (0.000 sec)

MariaDB [(none)]> grant replication slave on *.* to 'slave'@'%';
Query OK, 0 rows affected (0.000 sec)

MariaDB [(none)]> show grants for slave@'%';
+-----------------------------------------------------------------------------------------------------------------------------------------------------------+
| Grants for slave@%
                                                                 |
+-----------------------------------------------------------------------------------------------------------------------------------------------------------+
| GRANT REPLICATION SLAVE, REPLICATION MASTER ADMIN, SLAVE MONITOR ON *.* TO `slave`@`%` IDENTIFIED BY PASSWORD '*6FD75C493B2445E4A0E072014C52A0CAEEC44696' |
+-----------------------------------------------------------------------------------------------------------------------------------------------------------+
1 row in set (0.000 sec)


# 用另外一个数据库登录

mysql -h 39.99.50.197 -u slave  -p'13333'
mysql> show databases;
+--------------------+
| Database           |
+--------------------+
| information_schema |
+--------------------+
1 row in set (0.06 sec)

从数据库里操作
change master to master_host='39.99.50.197',master_port=3306,master_user='slave',master_password='12222',master_log_file='mysql-bin.000004',master_log_pos=1711;
start slave;
show slave status\G # 查看三个进程是否正常运行 这个会一直运行的重启了不要怕
```
