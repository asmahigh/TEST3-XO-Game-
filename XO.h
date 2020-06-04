// XO.h
#ifndef HEADER_FILE_NAME
#define HEADER_FILE_NAME



#define press_to_move_right    				(!(GPIO_PORTF_DATA_R&0x10) && (GPIO_PORTF_DATA_R&0x01))
#define press_to_move_left 						(!(GPIO_PORTF_DATA_R&0x01) && (GPIO_PORTF_DATA_R&0x10))
#define press_to_play									(!(GPIO_PORTF_DATA_R&0x10) && !(GPIO_PORTF_DATA_R&0x01))
#define still_pressing_to_move_right  (!(GPIO_PORTF_DATA_R&0x10))
#define still_pressing_to_move_left		(!(GPIO_PORTF_DATA_R&0x01))
#define still_pressing_to_play 				(!(GPIO_PORTF_DATA_R&0x10) && !(GPIO_PORTF_DATA_R&0x01))
#define Empty            0
#define X                1
#define O                2
#define StillPlaying		-1
#define tie							-2


struct Cell {
	unsigned long xCoord;					// x cooordinat;
	unsigned long yCoord;					// y coordinate
	char state;										// Empty if 0, X if 1, O if 2
};


void delay_100ms(unsigned long count); 	// time delay in 0.1 seconds
void PortF_Init(void);
char FindWinner(void);
void MoveRight(void);
void MoveLeft(void);
void playX(void);
void playO(void);
void GameInit(void);

#endif
