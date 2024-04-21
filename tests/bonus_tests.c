/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_tests.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 21:30:39 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/04/21 19:46:32 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>
#include <float.h>


void	tests(const char *format, ...)
{
	int	count;
	va_list	ap;
	
	count = 0;
	va_start(ap, format);
	printf("printf:\t\t"); count = vprintf(format, ap);
	printf("\t(%d)\n", count);
	ft_printf("ft_printf :\t"); count = ft_vprintf(format, ap);
	printf("\t(%d)\n", count);
	va_end(ap);
}

int	main(void)
{
	int			n = 42;
	char		s[] = "";
	int			i1 = INT_MIN;
	void		*p = NULL;

	printf("Bonus part : testing flags ...\n");
	printf("\n>> Conversion %%c : one option only\n");
	tests("|%-c|%0c|%3c|%-c|%0c|%3c|%-c|%0c|%3c|%-c|%3c|", 'a', 'b', 'c', n, n, n, *s, *s, *s, i1, i1, i1);
	tests("|%#c|% c|%+c|%.3c|%#c|% c|%+c|%.3c|%#c|% c|%+c|%.3c|%#c|% c|%+c|%.3c|", 'a', 'b', 'c', 'd', n, n, n, n, *s, *s, *s, *s, i1, i1, i1, i1);
	printf(">> Conversion %%c : width + one flag\n");
	tests("|%-3c|%03c|%-3c|%03c|%-3c|%03c|%-3c|%03c|", 'a', 'b', n, n, *s, *s, i1, i1);
	tests("|%#3c|% 3c|%+3c|%#3c|% 3c|%+3c|%#3c|% 3c|%+3c|%#3c|% 3c|%+3c|", 'a', 'b', 'c', n, n, n, *s, *s, *s, i1, i1, i1);
	printf(">> Conversion %%c : width + precision + multiple flags\n");
	tests("|%-03.2c|%- 3.2c|%-+3.2c|%-#3.2c|%0 3.2c|%0+3.2c|%0#3.2c|%-+ 3.2c|%+0 3.2c|%+ #3.2c|%+-03.2c|", 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k');
	// convert to unsigned char
	printf("\n>> Conversion %%s : one option only\n");
	tests("|%-s|%0s|%6s|%.4s|%-s|%0s|%6s|%.4s|", "hello", "hello", "hello", "hello", s, s, s, s);
	tests("|%#s|% s|%+s|%#s|% s|%+s|", "hello", "hello", "hello", s, s, s);
	printf(">> Conversion %%c : width + one flag\n");
	tests("|%-4s|%04s|%-5s|%05s|%-6s|%06s|%-4s|%04s|%-5s|%05s|%-6s|%06s|", "hello", "hello", "hello", "hello", "hello", "hello", s, s, s, s, s, s);
	tests("|%#4s|% 4s|%+4s|%#5s|% 5s|%+5s|%#6s|% 6s|%+6s|%#4s|% 4s|%+4s|%#5s|% 5s|%+5s|%#6s|% 6s|%+6s|", "hello", "hello", "hello", "hello", "hello", "hello", "hello", "hello", "hello", s, s, s, s, s, s, s, s, s);
	printf(">> Conversion %%c : precision + one flag\n");
	tests("|%-.4s|%0.4s|%-.5s|%0.5s|%-.6s|%0.6s|%-.4s|%0.4s|%-.5s|%0.5s|%-.6s|%0.6s|", "hello", "hello", "hello", "hello", "hello", "hello", s, s, s, s, s, s);
	tests("|%#.4s|% .4s|%+.4s|%#.5s|% .5s|%+.5s|%#.6s|% .6s|%+.6s|%#.4s|% .4s|%+.4s|%#.5s|% .5s|%+.5s|%#.6s|% .6s|%+.6s|", "hello", "hello", "hello", "hello", "hello", "hello", "hello", "hello", "hello", s, s, s, s, s, s, s, s, s);
	printf(">> Conversion %%c : width + precision + one flag max.\n");
	tests("|%4.4s|%-4.4s|%04.4s|%4.5s|%-4.5s|%04.5s|%4.6s|%-4.6s|%04.6s|%4.4s|%-4.4s|%04.4s|%4.5s|%-4.5s|%04.5s|%4.6s|%-4.6s|%04.6s|", "hello", "hello", "hello", "hello", "hello", "hello", "hello", "hello", "hello", s, s, s, s, s, s, s, s, s);
	tests("|%5.4s|%-5.4s|%05.4s|%5.5s|%-5.5s|%05.5s|%5.6s|%-5.6s|%05.6s|%5.4s|%-5.4s|%05.4s|%5.5s|%-5.5s|%05.5s|%5.6s|%-5.6s|%05.6s|", "hello", "hello", "hello", "hello", "hello", "hello", "hello", "hello", "hello", s, s, s, s, s, s, s, s, s);
	tests("|%6.4s|%-6.4s|%06.4s|%6.5s|%-6.5s|%06.5s|%6.6s|%-6.6s|%06.6s|%6.4s|%-6.4s|%06.4s|%6.5s|%-6.5s|%06.5s|%6.6s|%-6.6s|%06.6s|", "hello", "hello", "hello", "hello", "hello", "hello", "hello", "hello", "hello", s, s, s, s, s, s, s, s, s);
	tests("|%#4.4s|% 4.4s|%+4.4s|%#4.5s|% 4.5s|%+4.5s|%#4.6s|% 4.6s|%+4.6s|%#4.4s|% 4.4s|%+4.4s|%#4.5s|% 4.5s|%+4.5s|%#4.6s|% 4.6s|%+4.6s|", "hello", "hello", "hello", "hello", "hello", "hello", "hello", "hello", "hello", s, s, s, s, s, s, s, s, s);
	tests("|%#5.4s|% 5.4s|%+5.4s|%#5.5s|% 5.5s|%+5.5s|%#5.6s|% 5.6s|%+5.6s|%#5.4s|% 5.4s|%+5.4s|%#5.5s|% 5.5s|%+5.5s|%#5.6s|% 5.6s|%+5.6s|", "hello", "hello", "hello", "hello", "hello", "hello", "hello", "hello", "hello", s, s, s, s, s, s, s, s, s);
	tests("|%#6.4s|% 6.4s|%+6.4s|%#6.5s|% 6.5s|%+6.5s|%#6.6s|% 6.6s|%+6.6s|%#6.4s|% 6.4s|%+6.4s|%#6.5s|% 6.5s|%+6.5s|%#6.6s|% 6.6s|%+6.6s|", "hello", "hello", "hello", "hello", "hello", "hello", "hello", "hello", "hello", s, s, s, s, s, s, s, s, s);
	printf(">> Conversion %%c : width + precision + multiple flags\n");
	tests("|%-0s|%-#s|%- s|%-+s|%0#s|%0 s|%0+s|%-0+s|%-+ s|%-0s|%-#s|%- s|%-+s|%0#s|%0 s|%0+s|%-0+s|%-+ s|", "hello", "hello", "hello", "hello", "hello", "hello", "hello", "hello", "hello", s, s, s, s, s, s, s, s, s);
	tests("|%-06s|%-#6s|%- 6s|%-+6s|%0#6s|%0 6s|%0+6s|%-0+6s|%-+ 6s|%-06s|%-#6s|%- 6s|%-+6s|%0#6s|%0 6s|%0+6s|%-0+6s|%-+ 6s|", "hello", "hello", "hello", "hello", "hello", "hello", "hello", "hello", "hello", s, s, s, s, s, s, s, s, s);
	tests("|%-0.4s|%-#.4s|%- .4s|%-+.4s|%0#.4s|%0 .4s|%0+.4s|%-0+.4s|%-+ .4s|%-0.4s|%-#.4s|%- .4s|%-+.4s|%0#.4s|%0 .4s|%0+.4s|%-0+.4s|%-+ .4s|", "hello", "hello", "hello", "hello", "hello", "hello", "hello", "hello", "hello", s, s, s, s, s, s, s, s, s);
	tests("|%-06.4s|%-#6.4s|%- 6.4s|%-+6.4s|%0#6.4s|%0 6.4s|%0+6.4s|%-0+6.4s|%-+ 6.4s|%-06.4s|%-#6.4s|%- 6.4s|%-+6.4s|%0#6.4s|%0 6.4s|%0+6.4s|%-0+6.4s|%-+ 6.4s|", "hello", "hello", "hello", "hello", "hello", "hello", "hello", "hello", "hello", s, s, s, s, s, s, s, s, s);
	
	printf("\n>> Conversion %%p : one option only\n"); // flags 0, blank, + and precision not standard, thus not tested
	tests("|%-p|%15p|%-p|%15p|", s, s, p, p);
	tests("|%#p|%#p|", s, p); // no effect
	printf(">> Conversion %%p : width + one flag\n");
	tests("|%-15p|%-15p|", s, p);
	tests("|%#15p|%#15p|", s, p); // no effect
	printf(">> Conversion %%p : width + multiple flags\n");
	tests("|%-#15p|%-#15p|", s, p);
	
	printf("\n>> Conversion %%d %%i : one option only\n");
	tests("|%-d|%0d|% d|%+d|%6d|%.4d|%-d|%0d|% d|%+d|%6d|%.4d|%-d|%0d|% d|%+d|%6d|%.4d|", n, n, n, n, n, n, n, i1, i1, i1, i1, i1, i1, 0, 0, 0, 0, 0, 0);
	tests("|%#d|%#d|%#d|", n, i1, 0);
	printf(">> Conversion %%d %%i : width + one flag\n");
	tests("|%-6d|%06d|% 6d|%+6d|%-6d|%06d|% 6d|%+6d|%-6d|%06d|% 6d|%+6d|", n, n, n, n, i1, i1, i1, i1, 0, 0, 0, 0);
	tests("|%#6d|%#6d|%#6d|", n, i1, 0);
	printf(">> Conversion %%d %%i : precision + one flag\n");
	tests("|%-.4d|%0.4d|% .4d|%+.4d|%-.4d|%0.4d|% .4d|%+.4d|%-.4d|%0.4d|% .4d|%+.4d|", n, n, n, n, i1, i1, i1, i1, 0, 0, 0, 0);
	tests("|%#.4d|%#.4d|%#.4d|", n, i1, 0);
	printf(">> Conversion %%d %%i : width + precision + one flag max.\n");
	tests("|%6.4d|%-6.4d|%06.4d|% 6.4d|%+6.4d|%6.4d|%-6.4d|%06.4d|% 6.4d|%+6.4d|%6.4d|%-6.4d|%06.4d|% 6.4d|%+6.4d|", n, n, n, n, n, i1, i1, i1, i1, i1, 0, 0, 0, 0, 0);
	tests("|%#6.4d|%#6.4d|%#6.4d|", n, i1, 0);
	tests("|%4.6d|%-4.6d|%04.6d|% 4.6d|%+4.6d|%4.6d|%-4.6d|%04.6d|% 4.6d|%+4.6d|%4.6d|%-4.6d|%04.6d|% 4.6d|%+4.6d|", n, n, n, n, n, i1, i1, i1, i1, i1, 0, 0, 0, 0, 0);
	tests("|%#4.6d|%#4.6d|%#4.6d|", n, i1, 0);
	printf(">> Conversion %%d %%i : width + precision + multiple flags\n");
	tests("|%- 6.4d|%-+6.4d|%0 6.4d|%0+6.4d|%-0+ 6.4d|%- 6.4d|%-+6.4d|%0 6.4d|%0+6.4d|%-0+ 6.4d|%- 6.4d|%-+6.4d|%0 6.4d|%0+6.4d|%-0+ 6.4d|", n, n, n, n, n, i1, i1, i1, i1, i1, 0, 0, 0, 0, 0);
	tests("|%-#6.4d|%0#6.4d|% #6.4d|%+#6.4d|%-#+ 06.4d|%-#6.4d|%0#6.4d|% #6.4d|%+#6.4d|%-#+ 06.4d|%-#6.4d|%0#6.4d|% #6.4d|%+#6.4d|%-#+ 06.4d|", n, n, n, n, n, i1, i1, i1, i1, i1, 0, 0, 0, 0, 0);
	tests("|%- 4.6d|%-+4.6d|%0 4.6d|%0+4.6d|%-0+ 4.6d|%- 4.6d|%-+4.6d|%0 4.6d|%0+4.6d|%-0+ 4.6d|%- 4.6d|%-+4.6d|%0 4.6d|%0+4.6d|%-0+ 4.6d|", n, n, n, n, n, i1, i1, i1, i1, i1, 0, 0, 0, 0, 0);
	tests("|%-#4.6d|%0#4.6d|% #4.6d|%+#4.6d|%-#+ 04.6d|%-#4.6d|%0#4.6d|% #4.6d|%+#4.6d|%-#+ 04.6d|%-#4.6d|%0#4.6d|% #4.6d|%+#4.6d|%-#+ 04.6d|", n, n, n, n, n, i1, i1, i1, i1, i1, 0, 0, 0, 0, 0);
	printf(">> Conversion %%d %%i : precision 0 for value 0\n");
	tests("|%.d|%-.d|%0.d|% .d|%+.d|%3.d|", 0, 0, 0, 0, 0, 0);
	tests("|%-3.d|%03.d|% 3.d|%+3.d|%- 3.d|%-+3.d|%0 3.d|%0+3.d|%-0 +3.d|", 0, 0, 0, 0, 0, 0, 0, 0, 0);
	
	printf("\n>> Conversion %%u : one option only\n");
	tests("|%-u|%0u|%#u|% u|%+u|%6u|%.4u|%-u|%0u|%#u|% u|%+u|%6u|%.4u|%-u|%0u|%#u|% u|%+u|%6u|%.4u|", i1, i1, i1, i1, i1, i1, i1, n, n, n, n, n, n, n, 0, 0, 0, 0, 0, 0, 0);
	printf(">> Conversion %%u : width + one flag\n");
	tests("|%-6u|%06u|%#6u|% 6u|%+6u|%-6u|%06u|%#6u|% 6u|%+6u|%-6u|%06u|%#6u|% 6u|%+6u|", i1, i1, i1, i1, i1, i1, n, n, n, n, n, n, 0, 0, 0, 0, 0, 0);
	printf(">> Conversion %%u : precision + one flag\n");
	tests("|%-.4u|%0.4u|%#.4u|% .4u|%+.4u|%-.4u|%0.4u|%#.4u|% .4u|%+.4u|%-.4u|%0.4u|%#.4u|% .4u|%+.4u|", i1, i1, i1, i1, i1, n, n, n, n, n, 0, 0, 0, 0, 0);
	printf(">> Conversion %%u : width + precision + one flag max.\n");
	tests("|%6.4u|%-6.4u|%#6.4u|%06.4u|% 6.4u|%+6.4u|%6.4u|%-6.4u|%#6.4u|%06.4u|% 6.4u|%+6.4u|%6.4u|%-6.4u|%#6.4u|%06.4u|% 6.4u|%+6.4u|", i1, i1, i1, i1, i1, i1, n, n, n, n, n, n, 0, 0, 0, 0, 0, 0);
	tests("|%4.6u|%-4.6u|%#4.6u|%04.6u|% 4.6u|%+4.6u|%4.6u|%-4.6u|%#4.6u|%04.6u|% 4.6u|%+4.6u|%4.6u|%-4.6u|%#4.6u|%04.6u|% 4.6u|%+4.6u|", i1, i1, i1, i1, i1, i1, n, n, n, n, n, n, 0, 0, 0, 0, 0, 0);
	printf(">> Conversion %%u : width + precision + multiple flags\n");
	tests("|%- 6.4u|%-+6.4u|%0 6.4u|%0+6.4u|%-0 +6.4u|%- 6.4u|%-+6.4u|%0 6.4u|%0+6.4u|%-0 +6.4u|%- 6.4u|%-+6.4u|%0 6.4u|%0+6.4u|%-0 +6.4u|", i1, i1, i1, i1, i1, n, n, n, n, n, 0, 0, 0, 0, 0);
	tests("|%- 4.6u|%-+4.6u|%0 4.6u|%0+4.6u|%-0 +4.6u|%- 4.6u|%-+4.6u|%0 4.6u|%0+4.6u|%-0 +4.6u|%- 4.6u|%-+4.6u|%0 4.6u|%0+4.6u|%-0 +4.6u|", i1, i1, i1, i1, i1, n, n, n, n, n, 0, 0, 0, 0, 0);
	printf(">> Conversion %%u : precision 0 for value 0\n");
	tests("|%.u|%-.u|%0.u|% .u|%+.u|%3.u|", 0, 0, 0, 0, 0, 0);
	tests("|%-3.u|%03.u|% 3.u|%+3.u|%- 3.u|%-+3.u|%0 3.u|%0+3.u|%-0 +3.u|", 0, 0, 0, 0, 0, 0, 0, 0, 0);
	
	printf("\n>> Conversion %%x %%X : one option only\n");
	tests("|%-x|%0x|%#x|% x|%+x|%6x|%.4x|%-x|%0x|%#x|% x|%+x|%6x|%.4x|%-x|%0x|%#x|% x|%+x|%6x|%.4x|", i1, i1, i1, i1, i1, i1, n, n, n, n, n, n, n, 0, 0, 0, 0, 0, 0, 0);
	printf(">> Conversion %%x %%X : width + one flag\n");
	tests("|%-6x|%06x|%#6x|% 6x|%+6x|%-6x|%06x|%#6x|% 6x|%+6x|%-6x|%06x|%#6x|% 6x|%+6x|", i1, i1, i1, i1, i1, n, n, n, n, n, 0, 0, 0, 0, 0);
	printf(">> Conversion %%x %%X : precision + one flag\n");
	tests("|%-.4x|%0.4x|%#.4x|% .4x|%+.4x|%-.4x|%0.4x|%#.4x|% .4x|%+.4x|%-.4x|%0.4x|%#.4x|% .4x|%+.4x|", i1, i1, i1, i1, i1, n, n, n, n, n, 0, 0, 0, 0, 0);
	printf(">> Conversion %%x %%X : width + precision + one flag max.\n");
	tests("|%6.4x|%-6.4x|%06.4x|%#6.4x|% 6.4x|%+6.4x|%6.4x|%-6.4x|%06.4x|%#6.4x|% 6.4x|%+6.4x|%6.4x|%-6.4x|%06.4x|%#6.4x|% 6.4x|%+6.4x|", i1, i1, i1, i1, i1, i1, n, n, n, n, n, n, n, 0, 0, 0, 0, 0, 0, 0);
	tests("|%4.6x|%-4.6x|%04.6x|%#4.6x|% 4.6x|%+4.6x|%4.6x|%-4.6x|%04.6x|%#4.6x|% 4.6x|%+4.6x|%4.6x|%-4.6x|%04.6x|%#4.6x|% 4.6x|%+4.6x|", i1, i1, i1, i1, i1, i1, n, n, n, n, n, n, n, 0, 0, 0, 0, 0, 0, 0);
	printf(">> Conversion %%x %%X : width + precision + multiple flags\n");
	tests("|%-#6.4x|%- 6.4x|%-+6.4x|%0#6.4x|%0 6.4x|%0+6.4x|%# 6.4x|%#+6.4x|%-# 6.4x|%-#+6.4x|%0# 6.4x|%0#+6.4x|%-0# +6.4x|", i1, i1, i1, i1, i1, i1, i1, i1, i1, i1, i1, i1, i1);
	tests("|%-#4.6x|%- 4.6x|%-+4.6x|%0#4.6x|%0 4.6x|%0+4.6x|%# 4.6x|%#+4.6x|%-# 4.6x|%-#+4.6x|%0# 4.6x|%0#+4.6x|%-0# +4.6x|", i1, i1, i1, i1, i1, i1, i1, i1, i1, i1, i1, i1, i1);
	tests("|%-#6.4x|%- 6.4x|%-+6.4x|%0#6.4x|%0 6.4x|%0+6.4x|%# 6.4x|%#+6.4x|%-# 6.4x|%-#+6.4x|%0# 6.4x|%0#+6.4x|%-0# +6.4x|", n, n, n, n, n, n, n, n, n, n, n, n, n);
	tests("|%-#4.6x|%- 4.6x|%-+4.6x|%0#4.6x|%0 4.6x|%0+4.6x|%# 4.6x|%#+4.6x|%-# 4.6x|%-#+4.6x|%0# 4.6x|%0#+4.6x|%-0# +4.6x|", n, n, n, n, n, n, n, n, n, n, n, n, n);
	tests("|%-#6.4x|%- 6.4x|%-+6.4x|%0#6.4x|%0 6.4x|%0+6.4x|%# 6.4x|%#+6.4x|%-# 6.4x|%-#+6.4x|%0# 6.4x|%0#+6.4x|%-0# +6.4x|", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	tests("|%-#4.6x|%- 4.6x|%-+4.6x|%0#4.6x|%0 4.6x|%0+4.6x|%# 4.6x|%#+4.6x|%-# 4.6x|%-#+4.6x|%0# 4.6x|%0#+4.6x|%-0# +4.6x|", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	printf(">> Conversion %%x %%X : precision 0 for value 0\n");
	tests("|%.x|%-.x|%0.x|%#.x|% .x|%+.x|%3.x|", 0, 0, 0, 0, 0, 0, 0);
	tests("|%-3.x|%03.x|% 3.x|%+3.x|%- 3.x|%-+3.x|%0 3.x|%0+3.x|%-0 +3.x|%-#3.x|%0#3.x|%# 3.x|%+#3.x|%-# 3.x|%-#+3.x|%0# 3.x|%0#+3.x|%-0 #+3.x|", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	
	printf("\n>> Conversion %% : one option only\n");
	tests("|%-%|%0%|%#%|% %|%+%|%6%|%.4%|");
	printf(">> Conversion %% : width + one flag\n");
	tests("|%-6%|%06%|%#6%|% 6%|%+6%|");
	printf(">> Conversion %% : width + precision + multiple flags\n");
	tests("|%-6.4%|%06.4%|%-06.4%|%-0# +6.4%|"); 
	
	printf("\nEdge cases ...\n");
	printf(">> Unknown format specifier\n");
	tests("|%!|%3!|%03!|%-3!|");
	printf(">> %% symbol at the end of format string\n");
	tests("Hello !%-04");
	printf(">> Conversion %%c : argument is a string or NULL\n");
	tests("|%10c|%-10c|%010c|", "Marvin", "Marvin", "Marvin");
	tests("|%10c|%-10c|%010c|", NULL, NULL, NULL);
	printf(">> Conversion %%s : argument is NULL\n");
	tests("|%-s|%0s|%6s|%.4s|%-6s|%06s|%-.4s|%0.4s|%-6.4s|%06.4s|%-06.4s|", NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	printf(">> Conversion %%p : argument is NULL\n");
	tests("|%-p|%15p|%-15p|", NULL, NULL, NULL);
	printf(">> Conversion %%p : argument is an int\n");
	tests("|%-p|%15p|%-15p|", 42, 42, 42);
	printf(">> Precision : precision value starts with one or multiple zeros\n");
	tests("|%.04s|%.004d|%.0004u|%.00004x|", "hello", -42, 42, 42);
	printf(">> Precision : negative precision\n");
	tests("|%.-5s|%.-5d|%.-5u|%.-5x|", "hello", -42, 42, 42);
	tests("|%0.-6s|%10.-5d|%0.-5u|%#.-5x|", "hello", -42, 42, 42);


	/*	
	int	count = 0;
	printf(">> TEST\n");
	printf("printf:\t\t"); count = printf("_%.-3d_%.-3d_", 42, 0);
	printf("\t(%d)\n", count);
	ft_printf("ft_printf :\t"); count = ft_printf("_%.-3d_%.-3d_", 42, 0);
	printf("\t(%d)\n", count);
	printf("printf:\t\t"); count = printf("_%03.-3d_%03.-3d_", 42, 0);
	printf("\t(%d)\n", count);
	ft_printf("ft_printf :\t"); count = ft_printf("_%03.-3d_%03.-3d_", 42, 0);
	printf("\t(%d)\n", count);
	*/
	printf("%-4d", 42);
	
	return (0);
}