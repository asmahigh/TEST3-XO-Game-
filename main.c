#include "tm4c123gh6pm.h"
#include "Nokia5110.h"
#include "TExaS.h"
#include "XO.h"


extern char cell_no;
extern char turn;	
extern struct Cell CellsArray[9];

int main(void){
	char winner= -1;
	PortF_Init();  										      // Call initialization of port PF4, PF3, PF2, PF1, PF0    
  TExaS_Init(SSI0_Real_Nokia5110_Scope);  // Set system clock to 80 MHz
  Nokia5110_Init();
  Nokia5110_ClearBuffer();
	Nokia5110_DisplayBuffer();   						// Draw buffer
	GameInit();
	Nokia5110_DisplayBuffer();     					// Draw buffer

	
  while(1){
		delay_100ms(4);
		if (press_to_move_right) {
			MoveRight();
			Nokia5110_DisplayBuffer();
			while(still_pressing_to_move_right);
		}
		
		else if (press_to_move_left ) {
			MoveLeft();
			Nokia5110_DisplayBuffer();
			while(still_pressing_to_move_left);
		}
		
		else if (press_to_play) {
				if (turn == X){
					playX();
				}
				else if (turn == O){
					playO();
				}
			Nokia5110_DisplayBuffer();
			while(still_pressing_to_play);
		}

			
		winner = FindWinner();
		if (winner != StillPlaying) {
			delay_100ms(3);              // delay 3 sec at 50 MHz
			Nokia5110_Clear();
			Nokia5110_SetCursor(2, 2);
			Nokia5110_OutString("GAME OVER!");
			Nokia5110_SetCursor(2, 3);
			
			if (winner == tie) {
				Nokia5110_OutString("NOONE WON!");
				Nokia5110_SetCursor(2, 4);
				Nokia5110_OutString("Tie");
			}
			else if (winner == X) {
				Nokia5110_OutString("X WON");
				Nokia5110_SetCursor(2, 4);
				Nokia5110_OutString("Congrats");
			}
			else if (winner == O) {
				Nokia5110_OutString("O WON");
				Nokia5110_SetCursor(2, 4);
				Nokia5110_OutString("Congrats");
			}
			//while(1);
			delay_100ms(3);              // delay 4 sec at 50 MHz
			Nokia5110_PrintBMP(CellsArray[cell_no+1].xCoord, CellsArray[cell_no+1].yCoord, Empty, 0);
			GameInit();
			Nokia5110_DisplayBuffer();     					// Draw buffer

		}
		while (!(GPIO_PORTF_DATA_R&0x10) || !(GPIO_PORTF_DATA_R&0x01));
	}
}

