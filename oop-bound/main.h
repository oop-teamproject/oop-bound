/*

main.h
모든 클래스에서 자주 쓸 법한 상수만을 모아서 저장하는 헤더.

좌표계 정의를 위한 블럭 한 칸의 크기.
화면의 크기, 화면에 들어가는 블럭의 가로 세로 갯수.

*/

#ifndef __MAIN_H__
#define __MAIN_H__

#define BLOCK_SIZE 30 //블럭 한 칸의 크기를 기준으로 구역을 나눈다.
#define NUM_BLOCK_HEIGHT 20
#define NUM_BLOCK_WIDTH 30

#define WINDOW_HEIGHT NUM_BLOCK_HEIGHT * BLOCK_SIZE
#define WINDOW_WIDTH NUM_BLOCK_WIDTH * BLOCK_SIZE

#endif
