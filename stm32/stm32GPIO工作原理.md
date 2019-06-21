# stm32GPIO工作原理

## 1.GPIO的基本结构和工作方式

### 1.1GPIO的基本结构

![1560775195050](C:\Users\lyw\AppData\Roaming\Typora\typora-user-images\1560775195050.png)

**加了FT说明可以容忍5v**

### 1.2GPIO的工作方式

- 四种输入模式：上拉读0下拉读1

  ![1560775417035](C:\Users\lyw\AppData\Roaming\Typora\typora-user-images\1560775417035.png)

  - 输入浮空
  - 输入上拉：上面电阻连上，下面电阻断开
  - 输入下拉：下面电阻连上，上面电阻断开
  - 模拟输入：施密特触发器不会劫持

- 四种输出模式：

  ![1560775805244](C:\Users\lyw\AppData\Roaming\Typora\typora-user-images\1560775805244.png)

  - 开漏输出

  - 开漏复用功能

  - 推挽式输出

  - 推挽式复用功能

    ![1560776092217](C:\Users\lyw\AppData\Roaming\Typora\typora-user-images\1560776092217.png)

### 1.3 STM32引脚说明

![1560774992815](C:\Users\lyw\AppData\Roaming\Typora\typora-user-images\1560774992815.png)



## 2.GPIO寄存器说明

## STM32F01x GPIO引脚说明

