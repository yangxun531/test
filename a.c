//add something to test
//add another things to test

// �޷��˲�
// ���ݾ����жϣ�ȷ�����β�����������ƫ��ֵ���趨ΪA����ÿ�μ�⵽��ֵʱ�жϣ�
// �������ֵ���ϴ�ֵ֮��<=A���򱾴�ֵ��Ч��
// �������ֵ���ϴ�ֵֻ��>A,�򱾴�ֵ��Ч����������ֵ�����ϴ�ֵ���汾��ֵ��
// �ŵ㣺
// ����Ч�˷���żȻ����������������
// ȱ�㣺
// �޷��������������Եĸ��ţ�ƽ���Ȳ�
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



// ��λֵ�˲� 
// ����������
// ��������N�Σ�Nȡ����������N�β���ֵ����С���У�ȡ�м�ֵΪ������Чֵ
// �ŵ㣺
// ����Ч�˷���żȻ��������Ĳ������ţ����¶ȣ�Һλ�ı仯�����ı�����������õ��˲�Ч��
// ȱ�㣺
// ���������ٶȵȿ��ٱ仯�Ĳ�������
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



// ����ƽ���˲�
// ����������
// ����ȡN������ֵ����ƽ�����㣬Nֵ�ϴ�ʱ���ź�ƽ���Ƚϸߣ��������Ƚϵ�
// Nֵ��Сʱ���ź�ƽ���Ƚϵͣ��������Ƚϸߡ�Nֵ��ѡȡ��һ��12���ҡ�
// �ŵ㣺
// ��Ӧ�ڶ�һ�����������ŵ��źŽ����˲��������źŵ��ص�����һ��ƽ��ֵ���ź���ĳһ��ֵ��Χ�������²���
// ȱ�㣺
// ���ڲ����ٶȽ�����Ҫ�����ݼ����ٶȽϿ��ʵʱ���Ʋ������ã��Ƚ��˷�RAM
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


// ����ƽ���˲�������ƽ���˲�����
// ����������
// ������ȡN������ֵ����һ�����У����еĳ��ȹ̶�ΪN��ÿ�β�����һ�������ݷ����β�����ӵ�ԭ�����׵�һ�����ݣ��Ƚ��ȳ�����
// �Ѷ����е�N�����ݽ�������ƽ�����㣬�Ϳɻ���µ��˲������Nֵ��ѡȡ��һ��12.
// �ŵ㣺
// �������Ը��������õ��������ã�ƽ���ȸߣ���Ӧ�ڸ�Ƶ�񵴵�ϵͳ
// ȱ�㣺
// �����ȵͣ���żȻ���ֵ������Ը��ŵ��������ýϲ��������������������������Ĳ���ֵƫ���������������űȽ����صĳ���
// �˷�RAM
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



// ��λֵƽ���˲��������������ƽ���˲�����
// ����������
// �൱����λֵ�˲�+����ƽ���˲�����������N�����ݣ�ȥ��һ�����ֵ��һ����Сֵ��Ȼ�����N-2�����ݵ�����ƽ��ֵ��
// Nֵ��ѡȡ��3-14
// �ŵ㣺�ں��������˲������ŵ�
// ����żȻ���ֵ������Ը��ţ������������������������Ĳ���ֵƫ�
// ȱ�㣺
// �����ٶȽ��������㷨ƽ���˲�һ�����˷�RAM
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







































