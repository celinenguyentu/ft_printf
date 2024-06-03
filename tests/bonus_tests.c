/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_tests.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 21:30:39 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/06/03 21:30:46 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <fcntl.h>

void	tests(const char *format, ...)
{
	int	count;
	va_list	ap_og;
	va_list ap_ft;
	
	count = 0;
	va_start(ap_og, format);
	va_start(ap_ft, format);
	printf("printf:\t\t"); count = vprintf(format, ap_og);
	printf("\t(%d)\n", count);
	ft_printf("ft_printf :\t"); count = ft_vprintf(format, ap_ft);
	printf("\t(%d)\n", count);
	va_end(ap_og);
	va_end(ap_ft);
}

int	main(void)
{
	int			n = 42;
	char		s[] = "";
	int			i1 = INT_MIN;
	void		*p = NULL;

	printf("\nBONUS PART : testing flags ...\n");
	printf("\n>> Conversion %%c : one option only\n");
	tests("|%-c|%0c|%3c|%-c|%0c|%3c|%-c|%0c|%3c|%-c|%0c|%3c|", 'a', 'b', 'c', n, n, n, *s, *s, *s, i1, i1, i1);
	tests("|%#c|% c|%+c|%.3c|%#c|% c|%+c|%.3c|%#c|% c|%+c|%.3c|%#c|% c|%+c|%.3c|", 'a', 'b', 'c', 'd', n, n, n, n, *s, *s, *s, *s, i1, i1, i1, i1);
	printf(">> Conversion %%c : width + one flag\n");
	tests("|%-3c|%03c|%-3c|%03c|%-3c|%03c|%-3c|%03c|", 'a', 'b', n, n, *s, *s, i1, i1);
	tests("|%#3c|% 3c|%+3c|%#3c|% 3c|%+3c|%#3c|% 3c|%+3c|%#3c|% 3c|%+3c|", 'a', 'b', 'c', n, n, n, *s, *s, *s, i1, i1, i1);
	printf(">> Conversion %%c : width + precision + multiple flags\n");
	tests("|%-03.2c|%- 3.2c|%-+3.2c|%-#3.2c|%0 3.2c|%0+3.2c|%0#3.2c|%-+ 3.2c|%+0 3.2c|%+ #3.2c|%+-03.2c|", 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k');
	
	printf("\n>> Conversion %%s : one option only\n");
	tests("|%-s|%0s|%6s|%.4s|%-s|%0s|%6s|%.4s|", "hello", "hello", "hello", "hello", s, s, s, s);
	tests("|%#s|% s|%+s|%#s|% s|%+s|", "hello", "hello", "hello", s, s, s);
	printf(">> Conversion %%s : width + one flag\n");
	tests("|%-4s|%04s|%-5s|%05s|%-6s|%06s|%-4s|%04s|%-5s|%05s|%-6s|%06s|", "hello", "hello", "hello", "hello", "hello", "hello", s, s, s, s, s, s);
	tests("|%#4s|% 4s|%+4s|%#5s|% 5s|%+5s|%#6s|% 6s|%+6s|%#4s|% 4s|%+4s|%#5s|% 5s|%+5s|%#6s|% 6s|%+6s|", "hello", "hello", "hello", "hello", "hello", "hello", "hello", "hello", "hello", s, s, s, s, s, s, s, s, s);
	printf(">> Conversion %%s : precision + one flag\n");
	tests("|%-.4s|%0.4s|%-.5s|%0.5s|%-.6s|%0.6s|%-.4s|%0.4s|%-.5s|%0.5s|%-.6s|%0.6s|", "hello", "hello", "hello", "hello", "hello", "hello", s, s, s, s, s, s);
	tests("|%#.4s|% .4s|%+.4s|%#.5s|% .5s|%+.5s|%#.6s|% .6s|%+.6s|%#.4s|% .4s|%+.4s|%#.5s|% .5s|%+.5s|%#.6s|% .6s|%+.6s|", "hello", "hello", "hello", "hello", "hello", "hello", "hello", "hello", "hello", s, s, s, s, s, s, s, s, s);
	printf(">> Conversion %%s : width + precision + one flag max.\n");
	tests("|%4.4s|%-4.4s|%04.4s|%4.5s|%-4.5s|%04.5s|%4.6s|%-4.6s|%04.6s|%4.4s|%-4.4s|%04.4s|%4.5s|%-4.5s|%04.5s|%4.6s|%-4.6s|%04.6s|", "hello", "hello", "hello", "hello", "hello", "hello", "hello", "hello", "hello", s, s, s, s, s, s, s, s, s);
	tests("|%5.4s|%-5.4s|%05.4s|%5.5s|%-5.5s|%05.5s|%5.6s|%-5.6s|%05.6s|%5.4s|%-5.4s|%05.4s|%5.5s|%-5.5s|%05.5s|%5.6s|%-5.6s|%05.6s|", "hello", "hello", "hello", "hello", "hello", "hello", "hello", "hello", "hello", s, s, s, s, s, s, s, s, s);
	tests("|%6.4s|%-6.4s|%06.4s|%6.5s|%-6.5s|%06.5s|%6.6s|%-6.6s|%06.6s|%6.4s|%-6.4s|%06.4s|%6.5s|%-6.5s|%06.5s|%6.6s|%-6.6s|%06.6s|", "hello", "hello", "hello", "hello", "hello", "hello", "hello", "hello", "hello", s, s, s, s, s, s, s, s, s);
	tests("|%#4.4s|% 4.4s|%+4.4s|%#4.5s|% 4.5s|%+4.5s|%#4.6s|% 4.6s|%+4.6s|%#4.4s|% 4.4s|%+4.4s|%#4.5s|% 4.5s|%+4.5s|%#4.6s|% 4.6s|%+4.6s|", "hello", "hello", "hello", "hello", "hello", "hello", "hello", "hello", "hello", s, s, s, s, s, s, s, s, s);
	tests("|%#5.4s|% 5.4s|%+5.4s|%#5.5s|% 5.5s|%+5.5s|%#5.6s|% 5.6s|%+5.6s|%#5.4s|% 5.4s|%+5.4s|%#5.5s|% 5.5s|%+5.5s|%#5.6s|% 5.6s|%+5.6s|", "hello", "hello", "hello", "hello", "hello", "hello", "hello", "hello", "hello", s, s, s, s, s, s, s, s, s);
	tests("|%#6.4s|% 6.4s|%+6.4s|%#6.5s|% 6.5s|%+6.5s|%#6.6s|% 6.6s|%+6.6s|%#6.4s|% 6.4s|%+6.4s|%#6.5s|% 6.5s|%+6.5s|%#6.6s|% 6.6s|%+6.6s|", "hello", "hello", "hello", "hello", "hello", "hello", "hello", "hello", "hello", s, s, s, s, s, s, s, s, s);
	printf(">> Conversion %%s : width + precision + multiple flags\n");
	tests("|%-0s|%-#s|%- s|%-+s|%0#s|%0 s|%0+s|%-0+s|%-+ s|%-0s|%-#s|%- s|%-+s|%0#s|%0 s|%0+s|%-0+s|%-+ s|", "hello", "hello", "hello", "hello", "hello", "hello", "hello", "hello", "hello", s, s, s, s, s, s, s, s, s);
	tests("|%-06s|%-#6s|%- 6s|%-+6s|%0#6s|%0 6s|%0+6s|%-0+6s|%-+ 6s|%-06s|%-#6s|%- 6s|%-+6s|%0#6s|%0 6s|%0+6s|%-0+6s|%-+ 6s|", "hello", "hello", "hello", "hello", "hello", "hello", "hello", "hello", "hello", s, s, s, s, s, s, s, s, s);
	tests("|%-0.4s|%-#.4s|%- .4s|%-+.4s|%0#.4s|%0 .4s|%0+.4s|%-0+.4s|%-+ .4s|%-0.4s|%-#.4s|%- .4s|%-+.4s|%0#.4s|%0 .4s|%0+.4s|%-0+.4s|%-+ .4s|", "hello", "hello", "hello", "hello", "hello", "hello", "hello", "hello", "hello", s, s, s, s, s, s, s, s, s);
	tests("|%-06.4s|%-#6.4s|%- 6.4s|%-+6.4s|%0#6.4s|%0 6.4s|%0+6.4s|%-0+6.4s|%-+ 6.4s|%-06.4s|%-#6.4s|%- 6.4s|%-+6.4s|%0#6.4s|%0 6.4s|%0+6.4s|%-0+6.4s|%-+ 6.4s|", "hello", "hello", "hello", "hello", "hello", "hello", "hello", "hello", "hello", s, s, s, s, s, s, s, s, s);
	
	printf("\n>> Conversion %%p : one option only\n");
	tests("|%-p|%0p|% p|%+p|%15p|%.15p|%-p|%0p|% p|%+p|%15p|%.15p|", s, s, s, s, s, s, p, p, p, p, p, p);
	tests("|%#p|%#p|", s, p);
	printf(">> Conversion %%p : width + one flag\n");
	tests("|%-15p|%015p|% 15p|%+15p|%-15p|%015p|% 15p|%+15p|", s, s, s, s, p, p, p, p);
	tests("|%#15p|%#15p|", s, p);
	printf(">> Conversion %%p : precision + one flag\n");
	tests("|%-.15p|%0.15p|% .15p|%+.15p|%-.15p|%0.15p|% .15p|%+.15p|", s, s, s, s, p, p, p, p);
	tests("|%#.15p|%#.15p|", s, p);
	tests("|%-.0p|%0.0p|% .0p|%+.0p|%-.0p|%0.0p|% .0p|%+.0p|", s, s, s, s, p, p, p, p);
	tests("|%#.0p|%#.0p|", s, p);
	printf(">> Conversion %%p : width + precision + multiple flags\n");
	tests("|%- 15.12p|%-+15.12p|%0 15.12p|%0+15.12p|%-0 +15.12p|", s, s, s, s, s);
	tests("|%- 15.12p|%-+15.12p|%0 15.12p|%0+15.12p|%-0 +15.12p|", p, p, p, p, p);
	tests("|%- 12.15p|%-+12.15p|%0 12.15p|%0+12.15p|%-0 +12.15p|", s, s, s, s, s);
	tests("|%- 12.15p|%-+12.15p|%0 12.15p|%0+12.15p|%-0 +12.15p|", p, p, p, p, p);
	printf(">> Conversion %%p : precision 0\n");
	tests("|%- 15.0p|%-+15.0p|%0 15.0p|%0+15.0p|%-0 +15.0p|", s, s, s, s, s);
	tests("|%- 15.0p|%-+15.0p|%0 15.0p|%0+15.0p|%-0 +15.0p|", p, p, p, p, p);
	
	printf("\n>> Conversion %%d %%i : one option only\n");
	tests("|%-d|%0d|% d|%+d|%6d|%.4d|%-d|%0d|% d|%+d|%6d|%.4d|%-d|%0d|% d|%+d|%6d|%.4d|", n, n, n, n, n, n, i1, i1, i1, i1, i1, i1, 0, 0, 0, 0, 0, 0);
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
	tests("|%-6u|%06u|%#6u|% 6u|%+6u|%-6u|%06u|%#6u|% 6u|%+6u|%-6u|%06u|%#6u|% 6u|%+6u|", i1, i1, i1, i1, i1, n, n, n, n, n, 0, 0, 0, 0, 0);
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
	tests("|%-x|%0x|%#x|% x|%+x|%6x|%.4x|%-x|%0x|%#x|% x|%+x|%6x|%.4x|%-x|%0x|%#x|% x|%+x|%6x|%.4x|", i1, i1, i1, i1, i1, i1, i1, n, n, n, n, n, n, n, 0, 0, 0, 0, 0, 0, 0);
	printf(">> Conversion %%x %%X : width + one flag\n");
	tests("|%-6x|%06x|%#6x|% 6x|%+6x|%-6x|%06x|%#6x|% 6x|%+6x|%-6x|%06x|%#6x|% 6x|%+6x|", i1, i1, i1, i1, i1, n, n, n, n, n, 0, 0, 0, 0, 0);
	printf(">> Conversion %%x %%X : precision + one flag\n");
	tests("|%-.4x|%0.4x|%#.4x|% .4x|%+.4x|%-.4x|%0.4x|%#.4x|% .4x|%+.4x|%-.4x|%0.4x|%#.4x|% .4x|%+.4x|", i1, i1, i1, i1, i1, n, n, n, n, n, 0, 0, 0, 0, 0);
	printf(">> Conversion %%x %%X : width + precision + one flag max.\n");
	tests("|%6.4x|%-6.4x|%06.4x|%#6.4x|% 6.4x|%+6.4x|%6.4x|%-6.4x|%06.4x|%#6.4x|% 6.4x|%+6.4x|%6.4x|%-6.4x|%06.4x|%#6.4x|% 6.4x|%+6.4x|", i1, i1, i1, i1, i1, i1, n, n, n, n, n, n, 0, 0, 0, 0, 0, 0);
	tests("|%4.6x|%-4.6x|%04.6x|%#4.6x|% 4.6x|%+4.6x|%4.6x|%-4.6x|%04.6x|%#4.6x|% 4.6x|%+4.6x|%4.6x|%-4.6x|%04.6x|%#4.6x|% 4.6x|%+4.6x|", i1, i1, i1, i1, i1, i1, n, n, n, n, n, n, 0, 0, 0, 0, 0, 0);
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
	
	printf("\n>> Conversion %%o : one option only\n");
	tests("|%-o|%0o|%#o|% o|%+o|%6o|%.4o|%-o|%0o|%#o|% o|%+o|%6o|%.4o|%-o|%0o|%#o|% o|%+o|%6o|%.4o|", i1, i1, i1, i1, i1, i1, i1, n, n, n, n, n, n, n, 0, 0, 0, 0, 0, 0, 0);
	printf(">> Conversion %%o : width + one flag\n");
	tests("|%-6o|%06o|%#6o|% 6o|%+6o|%-6o|%06o|%#6o|% 6o|%+6o|%-6o|%06o|%#6o|% 6o|%+6o|", i1, i1, i1, i1, i1, n, n, n, n, n, 0, 0, 0, 0, 0);
	printf(">> Conversion %%o : precision + one flag\n");
	tests("|%-.4o|%0.4o|%#.4o|% .4o|%+.4o|%-.4o|%0.4o|%#.4o|% .4o|%+.4o|%-.4o|%0.4o|%#.4o|% .4o|%+.4o|", i1, i1, i1, i1, i1, n, n, n, n, n, 0, 0, 0, 0, 0);
	printf(">> Conversion %%o : width + precision + one flag max.\n");
	tests("|%6.4o|%-6.4o|%06.4o|%#6.4o|% 6.4o|%+6.4o|%6.4o|%-6.4o|%06.4o|%#6.4o|% 6.4o|%+6.4o|%6.4o|%-6.4o|%06.4o|%#6.4o|% 6.4o|%+6.4o|", i1, i1, i1, i1, i1, i1, n, n, n, n, n, n, 0, 0, 0, 0, 0, 0);
	tests("|%4.6o|%-4.6o|%04.6o|%#4.6o|% 4.6o|%+4.6o|%4.6o|%-4.6o|%04.6o|%#4.6o|% 4.6o|%+4.6o|%4.6o|%-4.6o|%04.6o|%#4.6o|% 4.6o|%+4.6o|", i1, i1, i1, i1, i1, i1, n, n, n, n, n, n, 0, 0, 0, 0, 0, 0);
	printf(">> Conversion %%o : width + precision + multiple flags\n");
	tests("|%-#6.4o|%- 6.4o|%-+6.4o|%0#6.4o|%0 6.4o|%0+6.4o|%# 6.4o|%#+6.4o|%-# 6.4o|%-#+6.4o|%0# 6.4o|%0#+6.4o|%-0# +6.4o|", i1, i1, i1, i1, i1, i1, i1, i1, i1, i1, i1, i1, i1);
	tests("|%-#4.6o|%- 4.6o|%-+4.6o|%0#4.6o|%0 4.6o|%0+4.6o|%# 4.6o|%#+4.6o|%-# 4.6o|%-#+4.6o|%0# 4.6o|%0#+4.6o|%-0# +4.6o|", i1, i1, i1, i1, i1, i1, i1, i1, i1, i1, i1, i1, i1);
	tests("|%-#6.4o|%- 6.4o|%-+6.4o|%0#6.4o|%0 6.4o|%0+6.4o|%# 6.4o|%#+6.4o|%-# 6.4o|%-#+6.4o|%0# 6.4o|%0#+6.4o|%-0# +6.4o|", n, n, n, n, n, n, n, n, n, n, n, n, n);
	tests("|%-#4.6o|%- 4.6o|%-+4.6o|%0#4.6o|%0 4.6o|%0+4.6o|%# 4.6o|%#+4.6o|%-# 4.6o|%-#+4.6o|%0# 4.6o|%0#+4.6o|%-0# +4.6o|", n, n, n, n, n, n, n, n, n, n, n, n, n);
	tests("|%-#6.4o|%- 6.4o|%-+6.4o|%0#6.4o|%0 6.4o|%0+6.4o|%# 6.4o|%#+6.4o|%-# 6.4o|%-#+6.4o|%0# 6.4o|%0#+6.4o|%-0# +6.4o|", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	tests("|%-#4.6o|%- 4.6o|%-+4.6o|%0#4.6o|%0 4.6o|%0+4.6o|%# 4.6o|%#+4.6o|%-# 4.6o|%-#+4.6o|%0# 4.6o|%0#+4.6o|%-0# +4.6o|", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	printf(">> Conversion %%o : precision 0 for value 0\n");
	tests("|%.o|%-.o|%0.o|%#.o|% .o|%+.o|%3.o|", 0, 0, 0, 0, 0, 0, 0);
	tests("|%-3.o|%03.o|% 3.o|%+3.o|%- 3.o|%-+3.o|%0 3.o|%0+3.o|%-0 +3.o|%-#3.o|%0#3.o|%# 3.o|%+#3.o|%-# 3.o|%-#+3.o|%0# 3.o|%0#+3.o|%-0 #+3.o|", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	
	printf("\n>> Conversion %% : one option only\n");
	tests("|%-%|%0%|%#%|% %|%+%|%6%|%.4%|");
	printf(">> Conversion %% : width + one flag\n");
	tests("|%-6%|%06%|%#6%|% 6%|%+6%|");
	printf(">> Conversion %% : width + precision + multiple flags\n");
	tests("|%-6.4%|%06.4%|%-06.4%|%-0# +6.4%|");

	printf("\n>> Using * notation\n");
	tests("|%*c|%*c|%-*c|%0*c|%3.*c|%*.*c|", 3, 'a', -3, 'b', 3, 'c', -3, 'd', 2, 'e', 3, -2, 'f');
	tests("|%*s|%*s|%-*s|%0*s|%6.*s|%*.*s|%*.*s|%*s|%*s|%-*s|%0*s|%6.*s|%*.*s|%*.*s|", 6, "hello", -6, "hello", 6, "hello", -6, "hello", 4, "hello", 6, 4, "hello", 6, -4, "hello", 6, NULL, -6, NULL, 6, NULL, -6, NULL, 4, NULL, 6, 4, NULL, 6, -4, NULL);
	tests("|%*p|%*p|%-*p|%*p|%*p|%-*p|", 15, s, -15, s, 15, s, 15, NULL, -15, NULL, 15, NULL);
	tests("|%*d|%*d|%-*d|%0*d|%+*d|%.*d|%.*d|%+*.*d|%0*.*d|%*d|%*d|%-*d|%0*d|%+*d|%.*d|%.*d|%+*.*d|%0*.*d|", 6, n, -6, n, 6, n, -6, n, 6, n, 4, n, -4, n, 6, -4, n, -6, 4, n, 6, 0, -6, 0, 6, 0, 6, 0, 6, 0, 4, 0, -4, 0, 6, -4, 0, -6, 4, 0);
	tests("|%*u|%*u|%-*u|%0*u|%.*u|%.*u|%-*.*u|%0*.*u|%0*.*u|%*u|%*u|%-*u|%0*u|%.*u|%.*u|%-*.*u|%0*.*u|%0*.*u|", 6, n, -6, n, 6, n, -6, n, 4, n, -4, n, 6, 4, n, -6, 4, n, 6, -4, n, 6, 0, -6, 0, 6, 0, -6, 0, 4, 0, -4, 0, 6, 4, 0, -6, 4, 0, 6, -4, 0);
	tests("|%*x|%*x|%-*x|%0*x|%#*x|%.*x|%.*x|%-*.*x|%0*.*x|%0*.*x|%#*.*x|%*x|%*x|%-*x|%0*x|%#*x|%.*x|%.*x|%-*.*x|%0*.*x|%0*.*x|%#*.*x|", 6, n, -6, n, 6, n, -6, n, 6, n, 4, n, -4, n, 6, 4, n, -6, 4, n, 6, -4, n, 6, -4, n, 6, 0, -6, 0, 6, 0, -6, 0, 6, 0, 4, 0, -4, 0, 6, 4, 0, -6, 4, 0, 6, -4, 0, 6, -4, 0);
	tests("|%*o|%*o|%-*o|%0*o|%#*o|%.*o|%.*o|%-*.*o|%0*.*o|%0*.*o|%#*.*o|%*o|%*o|%-*o|%0*o|%#*o|%.*o|%.*o|%-*.*o|%0*.*o|%0*.*o|%#*.*o|", 6, n, -6, n, 6, n, -6, n, 6, n, 4, n, -4, n, 6, 4, n, -6, 4, n, 6, -4, n, 6, -4, n, 6, 0, -6, 0, 6, 0, -6, 0, 6, 0, 4, 0, -4, 0, 6, 4, 0, -6, 4, 0, 6, -4, 0, 6, -4, 0);
	tests("|%*%|%-*%|%0*%|%*.*%|", 3, 3, -3, 3, 1);
	
	printf("\nEdge cases ...\n");
	printf(">> Unknown format specifier\n");
	tests("|%!|%3!|%.3!|%03!|%-3!|%#!|% !|%+!|");
	tests("|%3.y|%-#+3.y|%#+-3.y|% 0#3.y|%#- +03.y|%#-0 +2.3y|");
	tests("|%0.-2y|%#.-2y|%+ 3.-2y|%1.-+#2y|%3.-# 2y|");
	tests("|%0*.*y|%0*.*y|%0*.*y|%0*.*y|", 3, 2, -3, 2, 3, -2, -3, -2);
	tests("|%0#+*.*y|% -#*.*y|%#-0 +*.*y|", -3, 2, 3, -2, -3, -2);
	printf(">> %% symbol at the end of format string\n");
	tests("Hello !%-04");
	tests("Hello%.");
	tests("Hello%c%.", 'a');
	tests("Hello%.y%.");
	tests("Hello%c%.y%.", 'a');
	tests("Hello%.y%c%", 'a');
	printf(">> Width, flags and precision in random order\n");
	tests("%10.-d", 4);
	tests("%10+8#-d", 4);
	tests("%10+8.2#-d", 4);
	tests("%10+8.2#-4d", 4);
	tests("%10 *.2#06-*+d", 8, 4, 4);
	tests("%10.+03d", 4);
	tests("%2*00#.--3+ 10.2d", 6, 4);
	printf(">> Conversion %%c : argument is a string or NULL\n");
	tests("|%10c|%-10c|%010c|", "Marvin", "Marvin", "Marvin");
	tests("|%10c|%-10c|%010c|", NULL, NULL, NULL);
	printf(">> Conversion %%s : argument is NULL\n");
	tests("|%-s|%0s|%6s|%.4s|%.6s|%.8s|%-6s|%06s|%-.4s|%0.4s|%-6.4s|%06.4s|%-06.4s|", NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	printf(">> Conversion %%p : argument is NULL\n");
	tests("|%-p|%15p|%-15p|%.p|%3.p|", NULL, NULL, NULL, NULL, NULL);
	printf(">> Conversion %%p : argument is an int\n");
	tests("|%-p|%15p|%-15p|", 42, 42, 42);
	printf(">> Precision : precision value starts with one or multiple zeros\n");
	tests("|%.04s|%.004d|%.0004u|%.00004x|", "hello", -42, 42, 42);
	printf(">> Precision : negative precision\n");
	tests("|%.-5s|%.-5d|%.-5u|%.-5x|%.-5s|%.-5d|%.-5u|%.-5x|%.-5o|", "hello", -42, 42, 42, NULL, 0, 0, 0, 0);
	tests("|%0.-5s|%10.-5d|%0.-5u|%#.-5x|%0.-5s|%10.-5d|%0.-5u|%#.-5x|%#.-5o|", "hello", -42, 42, 42, NULL, 0, 0, 0, 0);
	tests("|%+3.-4d|%+5.-4d|%.-+4d|%#.-4o|", 42, 42, 42, 42);
	tests("|%.-03%.|");

	printf(">> Width overflow\n");
	tests("%3000000000c", 'a');
	tests("%2147483648s", "hello");
	tests("%2147483648d", 42);
	tests("%-2147483649d", 42);
#if defined (__APPLE__)
	tests("%2147483647d", 42);
	tests(" %2147483646d", 42); // printf doesn't print the spaces because of buffer implementation
	tests("  %2147483645d", 42);
	tests("  %2147483645c", 'a');
	tests("%*p", -2147483648, s);
	tests("%*d", 2147483649, 42);
	tests("%*d", -2147483649, 42);
	tests("%*d", -2147483647, 42);
	tests("   %2147483645s", "hello");
#endif
	printf(">> Precision overflow\n");
#if defined (__APPLE__)
	tests("%.2147483647p", s);
	tests(" %.2147483646p", s);
	tests("  %.2147483645p", s);
	tests("%.2147483647d", 1);
	tests("%.2147483647i", 12);
	tests("%.2147483647d", 123);
	tests(" %.2147483646i", 123);
	tests("  %.2147483645d", 123);
	tests("%.2147483647u", n);
	tests(" %.2147483646u", n);
	tests(" %.*d", -2147483650, 42);
#endif
	tests("%.2147483649i", 1);
	tests("%.2147483650d", 12);
	tests("%.2147483656i", 42424242);
	tests("%.2147483649d", -2);
	tests("%.3000000000d", 42);
	tests("%.2147483662p", s);
	tests("%.2147483648s", s);
	tests("%.2147483662s", s);
	tests("%.2147483662u", n);
	tests("%.2147483653x", 424242);
	tests("%.2147483655o", 424242);
	tests("%.*d", -2147483646, 42);
	tests("%010.*d", 2147483660, 42);
	printf(">> Handles write error\n");
    close(STDOUT_FILENO);
    int result = ft_printf("Call to %s fails because%2cf write.\n", "ft_printf", 'o');
    int fd = open("/dev/tty", O_WRONLY);
    if (result == -1)
        printf("OK: ft_printf returned -1\n");
    else
        printf("KO: ft_printf did not return -1\n");
	
	return (0);
}
