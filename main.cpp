#include <stdio.h>
#include <stdlib.h>

#define FILE_SRC_PATH	"MProccess.cpp"
#define FILE_DST_PATH	"MProccess_2.cpp"

int main()
{
	FILE	*fileSrc, *fileDst;
	char	ch;
	int		Cnt = 0;

	if( (fileSrc = fopen(FILE_SRC_PATH, "r")) == NULL )
	{
		exit(1);
	}
	if( (fileDst = fopen(FILE_DST_PATH, "w")) == NULL )
	{
		exit(1);
	}

	fseek(fileSrc, 0, SEEK_SET);
	
	do 
	{
		ch = fgetc(fileSrc);

		if (ch == '/')
		{
			ch = fgetc(fileSrc);

			if (ch == '/')
			{
				while(ch != '\n')
				{
					ch = fgetc(fileSrc);
				}
				continue;
			}
			
			if(ch == '*')
			{
				Cnt++;

				while(0 != Cnt)
				{
					ch = fgetc(fileSrc);

					if (ch == '*')
					{
						ch = fgetc(fileSrc);
						if ( ch == '/' )
						{
							Cnt--;
						}
					}
				}

				while(ch != '\n')
				{
					ch = fgetc(fileSrc);
				}
				ch = fgetc(fileSrc);
			}
			else
			{}
		}
		
		if (ch == '{')
		{			
			Cnt++;
			fputc(ch, fileDst);

			while(0 != Cnt)
			{
				ch = fgetc(fileSrc);
				if (ch == '}')
				{
					Cnt--;
				}
				else if (ch == '{')
				{
					Cnt++;
				}
			}
			fputc(ch, fileDst);
			ch = fgetc(fileSrc);
		}
		else
		{}

		if(ch != EOF)
		{
			fputc(ch, fileDst);
		}

	} while (ch != EOF);


	fclose(fileDst);
	fclose(fileSrc);

	return 0;
}