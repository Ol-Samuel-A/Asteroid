#include <stdio.h>
#include <allegro5\allegro.h>
#include <allegro5\allegro_image.h>
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_ttf.h>
#include <allegro5\allegro_primitives.h>
char fin=0;  //Variable que permite dar el fin.
char fond = 0;
int seleccion =0;
int juego=0;
void eleccion(int opc)
{
    switch(opc)
    {
        case 0:
            juego =1;
            break;
        case 1:
            seleccion = 1;
            break;
        case 2:
            fin = 1;
    }
    return;
}
char inicia(void)
{
    char fin=0;
    if(!al_init())
    {
        printf("No allegro");
        fin = 1;
    }
    if(!al_init_image_addon())
    {
        printf("No se pueden inicializar im%cgenes", 160);
        fin=1;
    }
    if(!al_init_font_addon()|| !al_init_ttf_addon())
    {
        printf("No se iniciaron las fuentes");
        fin = 1;
    }
    if(!al_install_keyboard())
    {
        printf("No se instalo teclado");
        fin = 1;
    }
    if(!al_init_primitives_addon())
    {
        printf("No se pudo iniciar primitives");
        fin = 1;
    }
    return fin;
}

int main (void)
{
    ALLEGRO_DISPLAY *disp; //*disp es un apuntador a ALLEGRO_DISPLAY. ALLEGRO_DISPLAY es el tipo de dato compuesto. Es una especie de arreglo.
    ALLEGRO_EVENT_QUEUE *eventos; //*eventos es un apuntador a ALLEGRO_EVENT_QUEUE.
    ALLEGRO_EVENT evento; //eventos es una estructura. Este guarda el evento en si, y lo manda a *eventos.
    ALLEGRO_BITMAP *fondo;
    ALLEGRO_BITMAP *fondoPart;
    ALLEGRO_BITMAP *Enter;
    ALLEGRO_BITMAP *icono;
    ALLEGRO_FONT *fuenteTit;
    ALLEGRO_FONT *fuenteSecc;
    ALLEGRO_FONT *fuenteSubt;
    ALLEGRO_FONT *fuenteExp;
    ALLEGRO_FONT *fuentePeque;
    ALLEGRO_TIMER *tempoA;
    float P1=335,Q1=240,P2=715,Q2=340; // son para la seleccion de el menu 
    char opc = 0; //seleccionar la opcion del menu
    fin= inicia();
    if (fin==0) //Si fin es del mismo valor que "0"...
    {
        disp=al_create_display(1000,700); //Función que crea la ventana, especificando también su tamaño (x,y).
        al_set_window_title(disp,"Astroid"); //Función para darle nombre a la ventana. Se especifica "disp" (la ventana creada anteriormente).
        tempoA = al_create_timer(0.5);
        eventos=al_create_event_queue(); //Función para generar la cola o fila de eventos. 
        al_register_event_source(eventos, al_get_display_event_source(disp)); //Registra lo que sucede en pantalla en la cola de eventos.
        al_register_event_source(eventos, al_get_timer_event_source(tempoA));
        al_register_event_source(eventos, al_get_keyboard_event_source());
        fondo=al_load_bitmap("Imag\\menu.png");
        fondoPart=al_load_bitmap("Imag\\fndJuego.png");
        icono=al_load_bitmap("Imag\\icon.png");
        Enter= al_load_bitmap("Imag\\Enter.png");
        fuenteTit=al_load_font("font\\fuent1.TTF",100,0);
        fuenteSecc=al_load_font("font\\fuent1.TTF",60,0);
        fuenteExp=al_load_font("font\\fuent1.TTF",20,0);
        fuenteSubt=al_load_font("font\\fuent1.TTF",40,0);
        fuentePeque=al_load_font("font\\fuent1.TTF",14,0);
        al_set_display_icon(disp,icono);
        if(!fuenteTit)
        {
            printf("No hay fuente");
            fin =1;
        } 
        if(!fondo || !icono || !fondoPart || !Enter)
        {
            printf("No se pudo cargar la im%cgen", 160);
            fin=1;
        }
        
       
        while (fin==0) //"while" se encargará de cerrar la pantalla
        {
                printf("\nse ha iniciado el ciclo");
                printf("El valor de seleccion es : %i\n",seleccion);
                printf("El valor de fondo es : %i\n",fond);
                if(al_event_queue_is_empty(eventos)) //"Si la línea de eventos es vacía"
                {
                    if (fond == 0)
                    {
                        al_draw_scaled_bitmap(fondo,0,0,728,410,0,0,1000,700,0);
                        al_draw_text(fuenteTit,al_map_rgb(255,255,255),250,80,0,"ASTROID");
                    }   // con respecto a la imagen,x,y tamaño y largo de imagen , x,y ---- ya resecto a la ventana , 050
                    switch(seleccion)
                    {
                        
                        case 0:
                            al_draw_text(fuenteSecc,al_map_rgb(255,255,255),395,250,0,"START");
                            al_draw_text(fuenteSecc,al_map_rgb(255,255,255),350,375,0,"TUTORIAL");
                            al_draw_text(fuenteSecc,al_map_rgb(255,255,255),450,500,0,"EXIT");
                            al_draw_rectangle(P1,Q1,P2,Q2,al_map_rgb(0,170,0),7);
                            al_draw_text(fuentePeque, al_map_rgb(223,13,13), 635, 655, 0, "Presiona enter para seleccionar");
                            al_draw_scaled_bitmap(Enter,0,0,362,368,900,630,60,60,0);
                            break;
                        case 1:
                            al_draw_filled_rectangle(100,220,900,650,al_map_rgb(0,0,0));
                            al_draw_rectangle(100,220,900,650,al_map_rgb(37,209,255),5);
                            al_draw_text(fuenteSecc,al_map_rgb(255,255,255),530,245,0,"TUTORIAL");
                            al_draw_text(fuenteSubt,al_map_rgb(255,255,255),170,295,0,"¿Como jugar?");
                            al_draw_text(fuenteExp, al_map_rgb(255,255,255), 150, 370, 0, "1. Inicio del juego: Desde el menú principal, selecciona");
                            al_draw_text(fuenteExp, al_map_rgb(255,255,255), 180, 390, 0, "START para comenzar.");

                            al_draw_text(fuenteExp, al_map_rgb(255,255,255), 150, 410, 0, "2. Controla tu nave: Usa las teclas de dirección para mover");
                            al_draw_text(fuenteExp, al_map_rgb(255,255,255), 180, 430, 0, "la nave por el espacio.");

                            al_draw_text(fuenteExp, al_map_rgb(255,255,255), 150, 460, 0, "3. Dispara: Usa la barra espaciadora para disparar a los");
                            al_draw_text(fuenteExp, al_map_rgb(255,255,255), 180, 480, 0, "asteroides que se acercan.");

                            al_draw_text(fuenteExp, al_map_rgb(255,255,255), 150, 510, 0, "4. Evita colisiones: Si un asteroide choca contigo,");
                            al_draw_text(fuenteExp, al_map_rgb(255,255,255), 180, 530, 0, "pierdes una vida.");

                            al_draw_text(fuenteExp, al_map_rgb(255,255,255), 150, 560, 0, "5. Gana puntos: Cada asteroide destruido te da puntos.");

                            al_draw_text(fuentePeque, al_map_rgb(255,255,255), 570, 610, 0, "Presiona enter para continuar");
                            al_draw_scaled_bitmap(Enter,0,0,362,368,830,580,60,60,0);
                            break;
                        case 2:
                            al_draw_filled_rectangle(100,220,900,650,al_map_rgb(0,0,0));
                            al_draw_rectangle(100,220,900,650,al_map_rgb(37,209,255),5);
                            al_draw_text(fuenteSecc,al_map_rgb(255,255,255),530,225,0,"TUTORIAL");
                            al_draw_text(fuenteSubt,al_map_rgb(255,255,255),170,295,0,"Controles de juego");
                            // Título
                            al_draw_text(fuenteSubt, al_map_rgb(255, 255, 0), 160, 370, 0, "Tecla                Acción");

                            // Controles
                            al_draw_text(fuenteExp, al_map_rgb(255, 255, 255), 160, 420, 0, " W  - - - - - - - - -  Acelera la nave en la dirección actual");
                            al_draw_text(fuenteExp, al_map_rgb(255, 255, 255), 160, 460, 0, " A  - - - - - - - - - - - - - - Gira la nave a la izquierda");
                            al_draw_text(fuenteExp, al_map_rgb(255, 255, 255), 160, 500, 0, " D  - - - - - - - - - - - - - - -Gira la nave a la derecha");
                            al_draw_text(fuenteExp, al_map_rgb(255, 255, 255), 160, 540, 0, " ESPACIO  - - - - - - - - - - Dispara un proyectil");
                            al_draw_text(fuenteExp, al_map_rgb(255, 255, 255), 160, 580, 0, " ESC  - - - - - - - - - - - - - - - - - - - Pausa ");


                            // el dibujito de explicacion de abajo
                            al_draw_text(fuentePeque, al_map_rgb(255,255,255), 570, 610, 0, "Presiona enter para continuar");
                            al_draw_scaled_bitmap(Enter,0,0,362,368,830,580,60,60,0);
                            break;
                    }
                    al_flip_display();
                }
                if(seleccion == 0)
                {
                    al_wait_for_event(eventos, &evento); //Espera a que se registre un evento
                    switch(evento.type)
                    {
                        case ALLEGRO_EVENT_DISPLAY_CLOSE:
                            printf("\nVentana cerrada \n");
                            fin=1;
                            break;
                        case ALLEGRO_EVENT_DISPLAY_SWITCH_IN:
                            printf("\nAdentro");
                            break;
                        case ALLEGRO_EVENT_DISPLAY_SWITCH_OUT:
                            printf("\nAfuera");
                            break;
                        case ALLEGRO_EVENT_KEY_DOWN:
                            printf("Tecla Alegro: %i \n",evento.keyboard.keycode);
                            if(evento.keyboard.keycode == 85)
                            {
                                Q1+=125;
                                Q2+=125;
                                opc+=1;
                                if(Q1 > 491)
                                {
                                    Q1 = 240;
                                    Q2 = 340;
                                    opc = 0;
                                }
                            }
                            if(evento.keyboard.keycode == 84)
                            {
                                Q1=Q1-125;
                                Q2=Q2-125;
                                opc = opc -1;
                                if(Q1 < 239)
                                {
                                    Q1 = 490;
                                    Q2 = 590;
                                    opc = 2;
                                }
                            }
                            if(evento.keyboard.keycode == 67)
                            {
                                eleccion(opc);
                            }
                            printf("Valor de opc: %i \n",opc);
                            break;
                        case ALLEGRO_EVENT_KEY_UP:    
                            break;
                    }
                }   
                if (seleccion == 1)
                {
                    al_wait_for_event(eventos, &evento);
                    switch(evento.type)
                    {
                        case ALLEGRO_EVENT_DISPLAY_CLOSE:
                            printf("\nVentana cerrada \n");
                            fin=1;
                            break;
                        case ALLEGRO_EVENT_DISPLAY_SWITCH_IN:
                            printf("\nAdentro");
                            break;
                        case ALLEGRO_EVENT_DISPLAY_SWITCH_OUT:
                            printf("\nAfuera");
                            break;
                        case ALLEGRO_EVENT_KEY_DOWN:
                            printf("Tecla Alegro: %i \n\n",evento.keyboard.keycode);
                            if(evento.keyboard.keycode == 67)
                            {
                                seleccion = 2;
                            }
                            break;
                        case ALLEGRO_EVENT_KEY_UP:    
                            break;
                    }
                }
                if(seleccion ==2)
                {
                    al_wait_for_event(eventos, &evento);
                    switch(evento.type)
                    {
                        case ALLEGRO_EVENT_DISPLAY_CLOSE:
                            printf("\nVentana cerrada \n");
                            fin=1;
                            break;
                        case ALLEGRO_EVENT_DISPLAY_SWITCH_IN:
                            printf("\nAdentro");
                            break;
                        case ALLEGRO_EVENT_DISPLAY_SWITCH_OUT:
                            printf("\nAfuera");
                            break;
                        case ALLEGRO_EVENT_KEY_DOWN:
                            printf("Tecla Alegro: %i \n\n",evento.keyboard.keycode);
                            if(evento.keyboard.keycode == 67)
                            {
                                seleccion = 0;
                            }
                            
                            break;
                        case ALLEGRO_EVENT_KEY_UP:    
                            break;
                    }
                
            }    
            if(juego ==1)
            {
                char finJueg = 0;
                al_start_timer(tempoA);
                int AstMAX=20;
                char pausa = 0;
                while(finJueg == 0)
                {
                    
                    if(al_event_queue_is_empty(eventos)) //"Si la línea de eventos es vacía"
                    {
                        al_draw_scaled_bitmap(fondoPart,0,0,728,410,0,0,1000,700,0);
                    }
                    al_flip_display();
                    al_wait_for_event(eventos, &evento);
                    switch(evento.type)
                    {
                        case ALLEGRO_EVENT_DISPLAY_CLOSE:
                            printf("ventana closed");
                            finJueg=1;
                            fin=1;
                            break;                        
                        case ALLEGRO_EVENT_DISPLAY_SWITCH_IN:
                            break;
                        case ALLEGRO_EVENT_DISPLAY_SWITCH_OUT:
                            break;
                        case ALLEGRO_EVENT_KEY_DOWN:
                            if(evento.keyboard.keycode == 59)
                                pausa=1;
                            break;
                        case ALLEGRO_EVENT_KEY_UP:    
                            break;

                        }
                }
            }
        }
        al_destroy_display(disp); //Función para destruir la ventana. Se especifica "disp" (la ventana creada anteriormente).
        al_destroy_event_queue(eventos);
        al_destroy_bitmap(fondo);
        al_destroy_bitmap(fondoPart);
        al_destroy_bitmap(icono);
        al_destroy_bitmap(Enter);
        al_destroy_font(fuenteTit);
        al_destroy_font(fuenteSecc);
        al_destroy_font(fuenteSubt);
        al_destroy_font(fuenteExp);
        al_destroy_font(fuentePeque);
        al_destroy_timer(tempoA);
    }
    return 0;
}