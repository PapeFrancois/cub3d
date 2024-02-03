/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepompid <hepompid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 11:27:33 by hepompid          #+#    #+#             */
/*   Updated: 2024/02/03 10:55:12 by hepompid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	print_title(void)
{
	printf("\033[6;31m");
	printf(" ________  ___  ___  ________          ________  ________     \n"
		"|\\   ____\\|\\  \\|\\  \\|\\   __  \\        |\\_____  \\|\\ "
		"  ___  \\    \n\\ \\  \\___|\\ \\  \\\\\\  \\ \\  \\|\\  \\      "
		" \\|____|\\ /\\ \\  \\_|\\  \\   \n \\ \\  \\    \\ \\  \\\\\\ "
		" \\ \\   __  \\            \\|\\  \\ \\  \\ \\\\  \\  \n  \\ \\ "
		" \\____\\ \\  \\\\\\  \\ \\  \\|\\  \\         __\\_\\   \\ \\  "
		"\\_\\\\  \\ \n   \\ \\_______\\ \\_______\\ \\_______\\      "
		" |\\________\\ \\_______\\\n    \\|_______|\\|_______|\\|_______|  "
		"      \\|_______|\\|_______|\n\n\n\033[0m");
	printf("\t 💖💗🥰💞 \033[1mTHE PERFECT CUB FILE TUTORIAL\033[0m 💞🥰💗💖"
		"\n\n\n\n\n");
}

static void	print_text(void)
{
	printf("💐 Hey gyal welcome to this t\033[31mUwU\033[0mtorial in which "
		"you'll learn\n"
		"     how to make a ✨perfect✨ cub file to launch cub3d !\n\n\n");
	printf("🫣  Did you make sure that the path to the map is good ? 🫣\n\n");
	printf("I know life is already so hard 😔🙏 but you'll have to respect some"
		" rules\n     to make your file readable...\n\n");
	printf("🕊️  First things first my angel, you have to make sure\n"
		"     that your file has the \".cub\" extention.\n\n");
	printf("🧭 Then, assure yourself that your \033[33mbeautiful\033[0m file "
		"indicates the link of\n     4 textures, one for the "
		"\033[31mNO\033[0mrth, one for the \033[31mSO\033[0muth, one for "
		"the \033[31mWE\033[0mst\n     and one for the \033[31mEA\033[0mst. "
		"They all must be on different lines\n     and contain the direction at"
		" its beginning.\n\n     \033[4mExample :\033[0m\n"
		"\tNO ./north_texture\n\tSO ./south_texture\n\tWE ./west_texture\n"
		"\tEA ./east_texture\n\n");
	printf("🎨 Also, check that you correctly indicated the colors of the "
		"\033[31mF\033[0mloor and \n     \033[31mC\033[0meiling. The "
		"colors have to be in \033[31mR\033[0m,\033[32mG\033[0m,"
		"\033[34mB\033[0m format (0 to 255), and the file lines\n     "
		"containing these informations in the same format than for the "
		"textures.\n\n     \033[4mExample :\033[0m\n\tF \033[31m255\033[0m,"
		"\033[32m0\033[0m,\033[34m0\033[0m\n\tC \033[31m120\033[0m,"
		"\033[32m120\033[0m,\033[34m50\033[0m\n\n\n");
	printf("\t  🫧 💗✨ Congrats sweet thing we're halfway done ! ✨💗🫧\n\n\n");
}

static void	print_text_end(void)
{
	printf("🗺️  To not be as lost🕵️  as in your life, you need a correct map.\n"
		"     Make sure that you put it at the end of the file, because you "
		"always\n     keep the best for last ! 🫶 ");
}

int	err(char *message)
{
	char	*str;

	ft_printf("Error\n%s\n\nDo you need to read the cub3d "
		"t\033[31mUwU\033[0mtorial ? (y/n) ", message);
	str = get_next_line(0);
	if (str[0] == 'y' && str[1] == '\n')
	{
		print_title();
		print_text();
		print_text_end();
	}
	free(str);
	return (ERROR);
}
