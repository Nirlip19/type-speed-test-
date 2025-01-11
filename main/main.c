#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>  
#include <stdbool.h>
#include <string.h>  


SDL_Window *window ; 
SDL_Renderer *render ;  
SDL_Rect rect ;
SDL_Rect TextBg ;  
TTF_Font *font ; 
SDL_Color color = {0 , 0 ,0} ;
bool is_runnig = true;  
char InputBuffer[1000]  ;  

void CreateWindow(){

	SDL_Init(SDL_INIT_VIDEO) ; 
        TTF_Init() ; 
 
       window  = SDL_CreateWindow("type test" , 20 ,20 , 1600 , 800,SDL_WINDOW_SHOWN ) ;
       render = SDL_CreateRenderer(window , -1 , 0 ) ; 
       font = TTF_OpenFont("Montserrat-Regular.ttf", 40); 
       if ( !font) printf("failed\n") ; 
}
void HandleInputBuffer(SDL_Event event ){
     
   switch(event.key.keysym.sym){
        case SDLK_BACKSPACE: 
                  InputBuffer[strlen(InputBuffer)-1] = 0 ; 
                       if ( rect.w > 0 )rect.w-=50 ; 
                      break ; 
        case SDLK_a:  strcat(InputBuffer , "a") ;       
                      rect.w+=50  ;
                      break ;
        case SDLK_b:  strcat(InputBuffer , "b") ;       
                      rect.w+=50  ;
                      break ;
        case SDLK_c:  strcat(InputBuffer , "c") ;       
                      rect.w+=50  ;
                      break ;
        case SDLK_d:  strcat(InputBuffer , "d") ;       
                      rect.w+=50  ;
                      break ;
        case SDLK_e:  strcat(InputBuffer , "e") ;       
                      rect.w+=50  ;
                      break ;
        case SDLK_f:  strcat(InputBuffer , "f") ;       
                      rect.w+=50  ;
                      break ;
        case SDLK_g:  strcat(InputBuffer , "g") ;       
                      rect.w+=50  ;
                      break ;
        case SDLK_h:  strcat(InputBuffer , "h") ;       
                      rect.w+=50  ;
                      break ;
        case SDLK_i:  strcat(InputBuffer , "i") ;       
                      rect.w+=50  ;
                      break ;
        case SDLK_j:  strcat(InputBuffer , "j") ;       
                      rect.w+=50  ;
                      break ;
        case SDLK_k:  strcat(InputBuffer , "k") ;       
                      rect.w+=50  ;
                      break ;
        case SDLK_l:  strcat(InputBuffer , "l") ;       
                      rect.w+=50  ;
                      break ;
        case SDLK_m:  strcat(InputBuffer , "m") ;       
                      rect.w+=50  ;
                      break ;
        case SDLK_n:  strcat(InputBuffer , "n") ;       
                      rect.w+=50  ;
                      break ;
        case SDLK_o:  strcat(InputBuffer , "o") ;       
                      rect.w+=50  ;
                      break ;
        case SDLK_p:  strcat(InputBuffer , "p") ;       
                      rect.w+=50  ;
                      break ;
        case SDLK_q:  strcat(InputBuffer , "q") ;       
                      rect.w+=50  ;
                      break ;
        case SDLK_r:  strcat(InputBuffer , "r") ;       
                      rect.w+=50  ;
                      break ;
        case SDLK_s:  strcat(InputBuffer , "s") ;       
                      rect.w+=50  ;
                      break ;
        case SDLK_t:  strcat(InputBuffer , "t") ;       
                      rect.w+=50  ;
                      break ;
        case SDLK_u:  strcat(InputBuffer , "u") ;       
                      rect.w+=50  ;
                      break ;
        case SDLK_v:  strcat(InputBuffer , "v") ;       
                      rect.w+=50  ;
                      break ;             
        case SDLK_w:  strcat(InputBuffer , "w") ;       
                      rect.w+=50  ;
                      break ;
        case SDLK_x:  strcat(InputBuffer , "x") ;       
                      rect.w+=50  ;
                      break ;
        case SDLK_y:  strcat(InputBuffer , "y") ;       
                      rect.w+=50  ;
                      break ;
        case SDLK_z:  strcat(InputBuffer , "z") ;       
                      rect.w+=50  ;
                      break ;
        case SDLK_SPACE :  strcat(InputBuffer , " ") ;       
                      rect.w+=50  ;
                      break ;            
       
     }
}
void HandleInput(){
         SDL_Event event ; 
         while ( SDL_PollEvent(&event)){  
                  if ( event.type == SDL_QUIT) is_runnig = false ; 
                  if (event.type == SDL_KEYDOWN){  
                       HandleInputBuffer(event) ; 
                   }
              }  

}
void LoadText(const char * text) {
      SDL_Surface * surface ; 
      SDL_Texture *texture ; 
      surface = TTF_RenderText_Solid(font , text  ,color );   
      TTF_SizeText(font , text , &rect.w , &rect.h ) ; 
      texture = SDL_CreateTextureFromSurface(render , surface ) ;
       
      SDL_RenderDrawRect(render , &rect ) ; 
      SDL_RenderCopy(render , texture , NULL , &rect) ;     
      
      SDL_FreeSurface(surface) ; 
      SDL_DestroyTexture(texture) ; 
      
} 
void MainLoop(){
       while ( is_runnig ){  
               SDL_SetRenderDrawColor(render , 0, 0 , 50 , 255 ) ; 
               SDL_RenderClear(render);  
               SDL_SetRenderDrawColor(render , 200 , 200, 200 , 255) ;
               SDL_RenderDrawRect( render , &TextBg ) ;   
               SDL_RenderFillRect(render , &TextBg) ; 
               HandleInput() ;   
               LoadText((const char *)InputBuffer) ; 
               SDL_RenderPresent(render) ;  
       }
     
      
}


      
void CleanUp(){

       TTF_Quit() ; 
       SDL_Quit() ;  
 

}

int main(){
        TextBg.x = 10 ; 
        TextBg.y = 400 ; 
        TextBg.w = 1500 ; 
        TextBg.h = 200 ; 
         
        rect.w = 25 ; 
        rect.h = 50 ; 
        rect.x = 20 ; 
        rect.y = 400 ;
        CreateWindow() ; 
        MainLoop() ; 
        CleanUp() ;  
     
}

