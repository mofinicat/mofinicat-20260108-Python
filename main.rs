```rust
fn main() {
    // 定义一个结构体来表示学生
    struct Student {
          name: String,
          age: u32,
}

    // 创建一个学生实例
    let student1 = Student {
              name: String::from("Alice"),
              age: 20,
    };

    // 打印学生的姓名和年龄
    println!("{} is {} years old.", student1.name, student1.age);

    // 定义一个函数来计算学生的年龄
    fn calculate_age(age: u32) -> u32 {
              age + 1
    }

    // 调用函数并打印结果
    println!("Next year, {} will be {} years old.", student1.name, calculate_age(student1.age));

    // 循环遍历1到5
    for i in 1..6 {
              println!("Number {}", i);
    }

    // 使用if语句判断一个数是否为偶数
    let number = 10;
    if number % 2 == 0 {
              println!("{} is even.", number);
    } else {
              println!("{} is odd.", number);
    }

    // 定义一个数组
    let numbers = [1, 2, 3, 4, 5];

    // 使用迭代器遍历数组
    for &num in &numbers {
              println!("Array element: {}", num);
    }

    // 使用let语句绑定变量的值
    let result = 2 * 3;
    println!("Result of multiplication is {}", result);

    // 使用match语句匹配不同的模式
    let number = 3;
    match number {
              1 => println!("One"),
              2 => println!("Two"),
              3 => println!("Three"),
              _ => println!("Not one, two, or three"),
    }

    // 使用宏来定义一个简单的计算器
    macro_rules! add {
              ($a:expr, $b:expr) => ($a + $b);
      }

    // 使用宏计算两个数的和
    println!("The sum is {}", add!(5, 7));

    // 使用闭包来定义一个计算平方的函数
    let closure = |x| x * x;
    println!("The square of 4 is {}", closure(4));

    // 使用结构体和枚举结合来表示不同的月份
    enum Month {
              January,
              February,
              March,
    }

    let month = Month::March;
    println!("It's {}", month as u32);
}
```
