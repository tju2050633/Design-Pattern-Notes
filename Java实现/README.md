
参考自：https://www.runoob.com/design-pattern/design-pattern-tutorial.html

### 目录结构

```c
.
├── README.md
├── bin # 编译结果
│   ├── AbstractFactory
│   │   ├── AbstractFactoryTest.class
│   │   ├── Color
│   │   ├── Factory
│   │   └── Shape
│   ├── ...
│   ├── ...
│   └── Main.class
└── src # 源码
    ├── AbstractFactory # 每个模式构成一个包
    │   ├── AbstractFactoryTest.java # 测试代码
    │   ├── Color		# 子包
    │   ├── Factory
    │   └── Shape
    ├── ...
    ├── ...
    └── Main.java # 入口，所有测试启动代码

```



### 运行

编译&运行（终端处于根目录）：

```
javac -d bin -cp src src/Main.java && java -cp bin Main
```

