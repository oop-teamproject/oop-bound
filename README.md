﻿# oop-bound

need a SFML-2.5.1 at C:\ to run .sln file.

# todo
file input/output

배열 형태 그대로 인풋아웃풋 할 거임. 1블럭당 1바이트로 줄여서.(Done)
포탈/스위치처럼 다른 블럭에 영향을 미치는 블럭은?(결국 따지고 보면 1바이트더라. Done)

Stage& operator=(const Stage&)를 위해서 BaseBlock.clonePtr()을 선언하고 싶다.(Done)
포인터를 할당해서 자신의 데이터를 복사해 넣은 뒤에 반환. polymorphism(Done)

Stage::std::list<BaseBlock*> drawlist;(하는 중..)
그려야 되는 블럭만을 저장. airblock 빼고, 폭탄 터지면 터진 폭블럭만 마지막에 한번 더 그리고(push_back) 등등..

level은 전역변수로 두든 전역 함수가 저걸 건드릴 수 있게 하든 해서scope를 코드 전체로 넓히고 싶다. main.h
그래도 그건 좀 아닌가? 아니야?
전역 함수 선택을 잘 하면?

Stage& stage = Level.getStageRef();(Done)

ball 클래스에 level 인스턴스 추가(추락할 때 목숨 떨구기용, 또 용도가 있나??)

base_block.collision_check(Ball& b) => base_block.collision_check(Ball& b, Level& lv);
충돌처리할 때 레벨에 영향을 끼치는 것들이 있다.(폭탄이 터지는 경우, 스위치를 누르는 경우 등)

