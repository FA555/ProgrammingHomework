/*������һ�ӱ�������֪��һ���ж����ˣ�����ʿ���Ŷӱ�����վ5��һ�ţ����1�ˣ�
վ6��һ�ţ����5�ˣ�վ7��һ�ţ����6�ˣ�վ11��һ�ţ����10�ˡ��ʺ��������ж��ٱ���
����Ϊһ������n(0<n<10000)��
���һ����С��n��������Ϊ���ſ���ӵ�б�����������Сֵ��*/
#include <stdio.h>
/*��д��ô������֪����ʵ������461�� 
{
	int i = 1;
	for (i=1; i<10000 ;i++)
	{
		if ((i%5==1)&&(i%6==5)&&(i%7==6)&&(i%11==10))
			break;
	 } 
	printf ("%d",i);
return 0; 

}*/
main()
{
	//����֪������С�ģ�ÿ�μ���5��6��7��11����С��������Ҳ����2310���γ���һ����
	int n;
	int ans;
	scanf("%d",&n);
	if (n<=461)
		ans = 461;
	else
	{
		int p;
		for (p = 1 ; 461+2310*p<10000 ;p++)
		{
			if ((461+2310*p)>n)
				break;
		}
		ans = (461+2310*p);
	 } 
	 printf("%d",ans);
return 0;
 } 