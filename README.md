# oop-bound

need a SFML-2.5.1 at C:\ to run .sln file.

# todo
file input/output

배열 형태 그대로 인풋아웃풋 할 거임. 1블럭당 1바이트로 줄여서.(Done)
포탈/스위치처럼 다른 블럭에 영향을 미치는 블럭은?(결국 따지고 보면 1바이트더라. Done)

Stage& operator=(const Stage&)를 위해서 BaseBlock.clonePtr()을 선언하고 싶다.(Done)
포인터를 할당해서 자신의 데이터를 복사해 넣은 뒤에 반환. polymorphism(Done)

Stage::std::list<BaseBlock*> drawlist;(Done)
그려야 되는 블럭만을 저장. airblock 빼고, 폭탄 터지면 터진 폭블럭만 마지막에 한번 더 그리고(push_back) 등등..

bool BaseBlock::check_collision(Ball& b) => gamestate BaseBlock::check_collision(Ball& b) (Done)
블럭이 스테이지를 업데이트 해야 하는 경우.
전역변수니 뭐니 이것저것 해보았지만 도저히 되는 게 없었다. 대신, 게임을 업데이트 해야 하는 경우
"어떻게" 업데이트해야 하는지를 반환하는 방식을 채택했다.(거의 한나절 꼬박 걸림.. 이 쉬운걸.)

