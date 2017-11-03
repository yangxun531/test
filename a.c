//add something to test
//add another things to test

// 限幅滤波
// 根据经验判断，确定两次采样允许的最大偏差值（设定为A），每次检测到新值时判断：
// 如果本次值与上次值之差<=A，则本次值有效，
// 如果本次值与上次值只差>A,则本次值无效，放弃本次值，用上次值代替本次值。
// 优点：
// 能有效克服因偶然因素引起的脉冲干扰
// 缺点：
// 无法抑制那种周期性的干扰，平滑度差
#define A 10

char value;

char filter()
{
	char new_value;
	new_value = get_ad();
	
	if ((new_value - value > A) || (value - new_value > A)) {
		return value;
	}
	
	return new_value;
}



// 中位值滤波 
// 方法解析：
// 连续采样N次（N取奇数），把N次采样值按大小排列，取中间值为本次有效值
// 优点：
// 能有效克服因偶然因素引起的波动干扰，对温度，液位的变化缓慢的被测参数有良好的滤波效果
// 缺点：
// 对流量，速度等快速变化的参数不宜
#define N 11

char filter()
{
	char value_buf[N];
	char count, i, j, temp;
	
	for (count = 0; count < N; count++) {
		value_buf[count] = get_ad;
		delay();
	}
	
	for (j = 0; j < N-1; j++) {
		for (i = 0; i < N-j; i++) {
			if (value_buf[i] > value_buf[i+1]) {
				temp = value_buf[i];
				value_buf[i] = value_buf[i+1];
				value_buf[i+1] = temp;
			}
		}
	}
	
	return value_buf[(N-1)/2];
}



// 算术平均滤波
// 方法解析：
// 连续取N个采样值进行平均运算，N值较大时：信号平滑度较高，但灵敏度较低
// N值较小时：信号平滑度较低，但灵敏度较高。N值的选取：一般12左右。
// 优点：
// 适应于对一般具有随机干扰的信号进行滤波，这样信号的特点是有一个平均值，信号在某一数值范围附近上下波动
// 缺点：
// 对于测量速度较慢或要求数据计算速度较快的实时控制并不适用，比较浪费RAM
#define N 12

char filter()
{
	int sum = 0;
	
	for (count = 0; count < N; count++) {
		sum += get_ad();
		delay();
	}
	
	return (char)(sum/N);
}


// 递推平均滤波（滑动平均滤波法）
// 方法解析：
// 把连续取N个采样值看成一个队列，队列的长度固定为N，每次采样到一个新数据放入队尾，并扔掉原来队首的一次数据（先进先出）。
// 把队列中的N个数据进行算术平均运算，就可获得新的滤波结果。N值的选取：一般12.
// 优点：
// 对周期性干扰有良好的抑制作用，平滑度高，适应于高频振荡的系统
// 缺点：
// 灵敏度低，对偶然出现的脉冲性干扰的抑制作用较差。不易消除由于脉冲干扰所引起打的采样值偏差，不适用于脉冲干扰比较严重的场合
// 浪费RAM
#define N 12

char value_buf[N];
char i = 0;

char filter()
{
	char count;
	int sum = 0;
	
	value_buf[i++] = get_ad();
	if (i == N)		i = 0;
	
	for (count =0; count < N; count++) {
		sum = value_buf[count];
	}
	
	return (char)(sum/N);
}



// 中位值平均滤波法（防脉冲干扰平均滤波法）
// 方法解析：
// 相当于中位值滤波+算术平均滤波，连续采样N个数据，去掉一个最大值和一个最小值，然后计算N-2个数据的算术平均值。
// N值的选取：3-14
// 优点：融合了两种滤波法的优点
// 对于偶然出现的脉冲性干扰，可消除由于脉冲干扰所引起的采样值偏差。
// 缺点：
// 测量速度较慢，和算法平均滤波一样，浪费RAM
#define N 12

char filter()
{
	char count, i, j;
	char value_buf[N];
	int sum = 0, temp = 0;
	
	for (count = 0; count < N; count++) {
		value_buf[count] = get_ad();
		delay();
	}
	
	for (j = 0; j < N-1; j++) {
		for (i = 0; i < N-j; i++) {
			if (value_buf[i] > value_buf[i+1]) {
				temp = value_buf[i];
				value_buf[i] = value_buf[i+1];
				value_buf[i+1] = temp;
			}
		}
	}
	
	for (count = 1; count < N-1; count++) {
		sum += value[count];
	}
	
	return (char)(sum/(N-2));
}







































