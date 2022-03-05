int gcd(int l,int r)
{
    int a = l<r?l:r;
    int b = l<r?r:l;
    int c;
	while(b)
	{
		c = a % b;
		a = b;
		b = c;
	}
    return a;
}
long long solution(const int w,const int h) {
    return (long long)w * h - (w+h-gcd(w,h));
}