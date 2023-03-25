/**
 * swap - function to swap two numbers
 * @x: char 1
 * @y: char 2
 *
 * @x and @y are swapped
 */
void swap(char *x, char *y)
{
	char t = *x;
	*x = *y;
	*y = t;
}


/**
 * reverse - function to reverse `buffer[i…j]`
 * @buffer: contained string to be reversed
 * @i: first index
 * @j: second index
 *
 * Return: reversed string
 */
char *reverse(char *buffer, int i, int j)
{
	while (i < j)
		swap(&buffer[i++], &buffer[j--]);

	return (buffer);
}


/**
 * *_itoa: Iterative function to change given number
 * to reuired base
 * @value: vale to be converted
 * @buffer: string to save binary value
 * @base: base to convert into
 * return number of base n
 */
char *_itoa(int value, char *buffer, int base)
{
	int n, i, r;

	if (base < 2 || base > 32)
		return (buffer);


	if (value < 0)
		value = -value;

	i = 0;
	n = value;

	while (n)
	{
		r = n % base;

		if (r >= 10)
			buffer[i++] = 65 + (r - 10);
		else
			buffer[i++] = 48 + r;

		n /= base;
	}

	if (i == 0)
		buffer[i++] = '0';

	if (value < 0 && base == 10)
		buffer[i++] = '-';

	buffer[i] = '\0';

	return (reverse(buffer, 0, i - 1));
}
