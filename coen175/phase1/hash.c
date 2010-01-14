/* hash.c */

int main(void)
{
    char c, *p, s[32];
    int sum;

    p = s;
    sum = 0;
    scanf("%s", s);

    while ((c = *p) != 0) {
	sum = (sum + c * 13) % 173;
	p = p + 1;
    }
    
    printf("%d\n", sum);
}
