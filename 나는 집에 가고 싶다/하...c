#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>

#define ROOM_WIDTH 10
#define HME_POS 1 //집 위치
#define BWL_POS (ROOM_WIDTH - 2) //냄비 위치
#define TWR_POS 3 //타워 위치
#define SCR_POS 6 //스크래쳐 위치
#define PRICE_MOUSE 1 //쥐 장난감 가격
#define PRICE_LASER     2 //레이저 포인터 가격
#define PRICE_SCRATCHER 4 //스크래쳐 가격
#define PRICE_TOWER 6 //타워 가격

int main(void) {

    printf("***야옹이와 스프***\n");
    printf("  /\\_/\\ \n");
    printf(" ( o.o )\n");
    printf("<|  ^ <|\n");
    printf(" |     |\\  \n");
    printf("         \\/  \n");

    char name[100]; // 고양이 이름 저장

    printf("야옹이의 이름을 입력해주세요(애국심을 갖고 한국어로 지어주세요).: ");
    scanf_s("%s", &name, 100);
    printf("야옹이의 이름은 %s입니다.", name);
    Sleep(1000); //1초 대기
    system("cls");



    int soup = 0; //수프 개수
    int relation = 2; //관계, 친밀도
    int leave = 2; //이전 위치, 즉 이미 떠나 자리, 3이상이면 이동
    int cat = 1; //고양이 위치
    int a = 0; //상호작용
    int CP = 0; //CP 포인트
    int feel = 3; //기분
	int scr = 0; //스크래쳐
	int twr = 0; //타워
    int laser = 0; //레이저 포인터
    int mouse = 0; //쥐 장남감
    int toy; // 장난감 수
    toy = laser + mouse; //레이저와 쥐 만을 장난감으로 여기는 세상임
    CP += ((feel - 1) > 0 ? (feel - 1) : 0) + relation; //누적하기 위해 + 붙이무
    int choice;
	int turnCount = 0; //턴 카운트
    char userAnswer[100];

    while (1) {
        if (feel < 0) {
            feel = 0; //기분은 0아래로 내려가면 안됨
        }
        if (feel > 3) {
            feel = 3; //기분은 3을 넘어갈 수 없음
        }
        printf("==========현재상태==========\n");
        printf("지금까지 만든 수프의 개수: %d개\n", soup);
        printf("CP: %d 포인트\n", CP);
        printf("고양이 기분(0~3): %d\n", feel);
        printf("집사와의 관계(0~4): %d\n", relation);
        printf("%s의 기분과 친밀도에 따라서 CP가 %d포인트 생산되었습니다.\n", name, CP);
        printf("보유 CP: %d 포인트\n", CP);

        if (feel == 0) {
            printf("기분이 매우 나쁩니다.\n");
            printf("기분이 매우 나쁜 %s은(는) 집으로 향합니다.\n", name);
        }
        if (feel == 1) {
            printf("심심해 합니다.\n");
        }
        if (feel == 2) {
            printf("식빵을 굽습니다.\n");
        }
        if (feel == 3) {
            printf("골골송을 부릅니다.\n");
        }

        if (relation == 0) {
            printf("곁에 오는 것조차 싫어합니다.\n");
        }
        else if (relation == 1) {
            printf("간식 자판기 취급입니다.\n");
        }
        else if (relation == 2) {
            printf("그럭저럭 쓸만한 집사입니다.\n");
        }
        else if (relation == 3) {
            printf("훌륭한 집사로 인정받고 있습니다.\n");
        }
        else if (relation == 4) {
            printf("집사 껌딱지입니다.\n");
        }
        else {
            printf("잘못된 친밀도 값입니다.\n");
        }
        printf("===============================\n\n");
        Sleep(500);

        for (int i = 0; i < ROOM_WIDTH; i++) {
            printf("#");
        }
        printf("\n");

        printf("#");
        for (int i = 1; i < ROOM_WIDTH - 1; i++) {
            if (i == HME_POS) {
                printf("H"); //집
            }
            else if (i == TWR_POS) {
                printf("T"); //타워
            }
            else if (i == SCR_POS) {
                printf("S"); //스크래쳐
            }
            else if (i == BWL_POS) { //냄비
                printf("B");
            }
            else {
                printf(" ");
            }
        }
        printf("#\n");

        printf("#");
        for (int i = 1; i < ROOM_WIDTH - 1; i++) {
            if (i == cat) {
                printf("C"); //고양이
            }
            else if (i == leave && cat != leave) {
                printf(".");
            }
            else {
                printf(" ");
            }
        }
        printf("#\n");

        for (int i = 0; i < ROOM_WIDTH; i++) {
            printf("#");
        }
        printf("\n");

        srand((unsigned)time(NULL));

        printf("주사위의 눈이 6 - %d이하면 그냥 기분이 나빠집니다.\n 주사위를 굴립니다. 또르륵...\n", relation);
        int rrr; //“아무 이유 없이 기분이 나빠집니다. 고양이니까?”라는 이유로 걍 굴리는 주사위
        rrr = rand() % 6 + 1;
        printf("%d이(가) 나왔습니다!\n", rrr);
        if (rrr <= 6 - relation) { //주사위 눈 6 - relation이하 친밀도 하락
            printf("기분이 나빠집니다.\n");
            feel--;
            if (feel < 0) {
                feel = 0; //기분은 0아래로 내려가면 안됨
            }
            if (feel > 3) {
                feel = 3; //기분은 3을 넘어갈 수 없음
            }
            if (relation < 0) {
                relation = 0; //친밀도는 0아래로 내려가면 안됨
            }
            if (relation > 4) {
                relation = 4; //친밀도는 4를 넘어갈 수 없음
            }
        }
        else {
            printf("다행히 기분이 나빠지지 않았습니다.\n");
        }
        printf("현재 기분: %d\n", feel);


        srand((unsigned)time(NULL));

        if (toy == 0) {
            printf("어떤 상호작용을 하시겠습니까?   0.아무것도 하지않음 1.긁어주기>> ");
            scanf_s("%d", &a);
            while (a != 0 && a != 1) {
                printf("0과 1중 하나를 입력하세요.\n");
                printf("어떤 상호작용을 하시겠습니까?   0.아무것도 하지않음 1.긁어주기>> ");
                scanf_s("%d", &a);
            }
        }
        if (toy == 1) {
            if (laser == 1) {
                printf("어떤 상호작용을 하시겠습니까?   0.아무것도 하지않음 1.긁어주기 2.레이저 포인터로 놀아주기>> ");
                scanf_s("%d", &a);
                while (a != 0 && a != 1 && a != 2) {
                    printf("0과 1과 2중 하나를 입력하세요.\n");
                    printf("어떤 상호작용을 하시겠습니까?   0.아무것도 하지않음 1.긁어주기 2.레이저 포인터로 놀아주기>> ");
                    scanf_s("%d", &a);
                }
            }
            if (mouse == 1) {
                printf("어떤 상호작용을 하시겠습니까?   0.아무것도 하지않음 1.긁어주기 2.장난감 쥐로 놀아주기>> ");
                scanf_s("%d", &a);
                while (a != 0 && a != 1 && a != 2) {
                    printf("0과 1과 2중 하나를 입력하세요.\n");
                    printf("어떤 상호작용을 하시겠습니까?   0.아무것도 하지않음 1.긁어주기 2.장난감 쥐로 놀아주기>> ");
                    scanf_s("%d", &a);
                }
            }
        }
        if (toy == 2) {
            printf("어떤 상호작용을 하시겠습니까?   0.아무것도 하지않음 1.긁어주기 2.레이저 포인터로 놀아주기 3.장난감 쥐로 놀아주기>> ");
            scanf_s("%d", &a);
            while (a != 0 && a != 1 && a != 2 && a != 3) {
                printf("0과 1과 2와 3중 하나를 입력하세요.\n");
                printf("어떤 상호작용을 하시겠습니까?   0.아무것도 하지않음 1.긁어주기 2.레이저 포인터로 놀아주기 3.장난감 쥐로 놀아주기>> ");
                scanf_s("%d", &a);
            }
        }

        if (a == 0) {

            printf("아무것도 하지 않습니다.\n %s의 기분이 나빠졌습니다.\n 4/6확룰로 친밀도가 떨어집니다.\n 주사위를 굴립니다. 또르륵...\n", name);
            feel--;
            int r; //주사위 수
            r = rand() % 6 + 1;
            printf("%d이(가) 나왔습니다!\n", r);
            if (r <= 4) { //주사위 눈 4이하 친밀도 하락
                printf("친밀도가 떨어집니다.\n");
                relation--;

                if (relation < 0) {
                    relation = 0; //친밀도는 0아래로 내려가면 안됨
                }
            }
            else {
                printf("다행히 친밀도가 떨어지지 않았습니다.\n");
            }
            printf("현재 친밀도: %d\n", relation);
            printf("현재 기분: %d\n", feel);
        }
        if (a == 1) {
            printf("%s의 턱을 긁어주었습니다.\n %s의 기분은 그대로입니다.\n 2/6확률로 친밀도가 높아집니다.\n 주사위를 굴립니다. 또르륵...\n", name, name);
            int rr; //주사위 수
            rr = rand() % 6 + 1;
            printf("%d이(가) 나왔습니다!\n", rr);
            if (rr >= 5) { //주사위 눈 5이상 친밀도 상승
                printf("친밀도가 상승합니다.\n");
                relation++;
                if (relation > 4) {
                    relation = 4; //친밀도는 4를 넘어갈 수 없음
                }
            }
            else {
                printf("친밀도는 그대로 입니다.\n");
            }
            printf("현재 친밀도: %d\n", relation);
        }
        if (a == 2) {
            printf("장난감 쥐로 %s와 놀아주었습니다.  %s의 기분이 조금 좋아졌습니다.\n", name, name);
            feel++;
            int rrrr; //주사위 수
            rrrr = rand() % 6 + 1;
            printf("%d이(가) 나왔습니다!\n", rrrr);
            if (rrrr >= 4) { //주사위 눈 4이상 친밀도 상승
                printf("친밀도가 상승합니다.\n");
                relation++;
                if (relation > 4) {
                    relation = 4; //친밀도는 4를 넘어갈 수 없음
                }
            }
        }
        if (a == 3) {
            printf("레이저 포인터로 %s와 신나게 놀아주었습니다. %s의 기분이 꽤 좋아졌습니다.\n", name, name);
            feel += 2;
            int rrrrr; //주사위 수
            rrrrr = rand() % 6 + 1;
            printf("%d이(가) 나왔습니다!\n", rrrrr);
			if (rrrrr >= 2) { //주사위 눈 2이상 친밀도 상승
				printf("친밀도가 상승합니다.\n");
				relation++;
				if (relation > 4) {
					relation = 4; //친밀도는 4를 넘어갈 수 없음
				}
			}
        }
        srand((unsigned)time(NULL));

        printf("\n상점에서 물건을 살 수 있습니다.\n"); //상점

        printf("어떤 물건을 구매할까요? (현재 CP: %d)\n", CP);
        printf("0. 아무것도 사지 않는다.\n");
        printf("1. 장난감 쥐: %d CP\n", PRICE_MOUSE);
        printf("2. 레이저 포인터: %d CP\n", PRICE_LASER);
        printf("3. 스크래쳐: %d CP\n", PRICE_SCRATCHER);
        printf("4. 캣 타워: %d CP\n", PRICE_TOWER);
        printf(">> ");
        scanf_s("%d", &choice);

        if (choice == 0) {
            printf("아무것도 사지 않고 상점을 나갑니다.\n");
        }
        if (choice == 1) {
            if (mouse == 1) {
                printf("품절된 제품입니다.\n 다음번에 다시 이용해주세요, 감사합니다.\n");
            }
            else if (CP < PRICE_MOUSE) {
                printf("CP가 부족합니다.\n");
            }
            else {
                CP -= PRICE_MOUSE;
                mouse++;
                mouse = 1;
                printf("장난감 쥐를 구매했습니다.\n");
                printf("보유 CP %d 포인트\n", CP);
            }
        }
        if (choice == 2) {
            if (laser == 1) {
                printf("품절된 제품입니다.\n 다음번에 다시 이용해주세요, 감사합니다.\n");
            }
            else if (CP < PRICE_LASER) {
                printf("CP가 부족합니다.\n");
            }
            else {
                CP -= PRICE_LASER;
                laser++;
                laser = 1;
                printf("레이저 포인터를 구매했습니다.\n");
                printf("보유 CP %d 포인트\n", CP);
            }
        }
        if (choice == 3) {
            if (scr == 1) {
                printf("품절된 제품입니다.\n 다음번에 다시 이용해주세요, 감사합니다.\n");
            }
            else if (CP < PRICE_SCRATCHER) {
                printf("CP가 부족합니다.\n");
            }
            else {
                CP -= PRICE_SCRATCHER;
                scr++;
                scr = 1;
                printf("스크래쳐를 구매했습니다.\n");
                printf("보유 CP %d 포인트\n", CP);

                int position = (rand() % 10) + 1;
                printf("스크래쳐를 집의 %d 위치에 배치했습니다.\n", position);
            }
        }
        if (choice == 4) {
            if (twr == 1) {
                printf("품절된 제품입니다.\n 다음번에 다시 이용해주세요, 감사합니다.\n");
            }
            else if (CP < PRICE_TOWER) {
                printf("CP가 부족합니다.\n");
            }
            else {
                CP -= PRICE_TOWER;
                twr++;
                twr = 1;
                printf("캣 타워를 구매했습니다.\n");
                printf("보유 CP %d 포인트\n", CP);
                int position = (rand() % 10) + 1;
                printf("캣 타워를 집의 %d 위치에 배치했습니다.\n", position);
            }
        }
        else {
            printf("저희 매장에서는 취급하고 있지 않은 제품입니다. 다른 매장으로 가주세요, 감사합니다.\n");
        }
               
                /* printf("%s 이동: 집사와 친밀할 수록 냄비로 이동할 확률이 높아집니다.\n", name); // ver. 1 좌우 이동 부분임
                 int limit = 6 - relation;
                 double probability = ((6 - limit + 1) / 6.0) * 100.0;
                 printf("주사위 눈이 %d이상이면 냄비쪽으로 이동합니다.\n", limit);
                 printf("→ 확률: 약 %.1f%%\n", probability);

                 srand((unsigned)time(NULL));

                 int dice = rand() % 6 + 1;
                 printf("주사위를 굴립니다. 또르륵...\n");
                 Sleep(1000);
                 printf("%d이(가) 나왔습니다!\n", dice);

                 if (dice >= limit) {
                     printf("냄비 쪽으로 이동합니다.\n\n");
                     if (cat < ROOM_WIDTH - 2) {
                         cat++;
                     }
                     else {
                         printf("하지만 벽에 막혀 움직일 수 없습니다.\n\n");
                     }
                 }
                 else {
                     printf("집 쪽으로 움직입니다.\n\n");
                     if (cat > 1) {
                         cat--;
                     }
                     else {
                         printf("하지만 벽에 막혀 움직일 수 없습니다.\n\n");
                     }
                 }
                 Sleep(1000);*/ // ver. 2에서는 좌우 이동 삭제

                if (feel == 0) {
                    printf("기분이 매우 나쁜 %s은(는) 집으로 향합니다.\n", name); //집으로 이동
                    if (cat < HME_POS && cat < ROOM_WIDTH - 1) {
                        cat++;
                    }
                    else (cat > HME_POS && cat > 0); {
                        cat--;
                    }
                }
                if (feel == 1) {
                    printf("%s은(는)심심해서 놀이기구 쪽으로 이동합니다.\n", name); //더 가까운 놀이기구 쪽으로 이동
                    if (cat < SCR_POS && cat < TWR_POS && cat < ROOM_WIDTH - 1) {
                        cat++;
                    }
                    else if (cat > SCR_POS && cat < TWR_POS && cat > 0) {
                        cat--;
                    }
                    else (cat != SCR_POS && cat != TWR_POS); {
                        printf("놀이기구가 없으면 기분 - 1: 놀거리가 없어서 기분이 매우 나빠집니다.\n");
                    }
                }
                if (feel == 2) {
                    printf("%s은(는) 기분좋게 식빵을 굽고 있습니다..\n", name); //제자리에 대기
                }
                if (feel == 3) {
                    printf("%s은(는) 골골송을 부르며 수프를 만들러 갑니다.\n", name); //냄비 쪽으로 이동
                    if (cat < BWL_POS && cat < ROOM_WIDTH - 1) {
                        cat++;
                    }
                    else (cat > BWL_POS && cat > 0); {
                        cat--;
                    }
                }

                // 상태에 따른 행동
                if (cat == HME_POS) { //집에 있을 때
                    printf("%s은(는) 자신의 집에서 편안함을 느낍니다.\n\n", name);
                    feel++;

                }
                else if (cat == BWL_POS) { //냄비에 있을 때
                    const char* soups[] = { "감자수프", "양송이수프", "브로콜리수프" };
                    int taste = rand() % 3;
                    soup++;
                    printf("%s이(가) %s를 만들었습니다!\n", name, soups[taste]);
                    printf("현재까지 만든 수프: %d개\n\n", soup);
                }
                else if (cat == SCR_POS) { //스크래쳐에 있을 때
                    printf("%s은(는) 스크래처를 긁고 놀았습니다. 기분이 조금 좋아졌습니다.\n", name);
                    feel++;
                }
                else (cat == TWR_POS); { //타워에 있을 때
                    printf("%s은(는) 캣타워를 뛰어다닙니다. 기분이 제법 좋아졌습니다.\n", name);
                    feel += 2;
                }

                turnCount++; // 턴이 시작될 때마다 턴 카운트 증가
                printf("\n--- 현재 %d번째 턴 ---\n", turnCount);

                if (turnCount % 3 == 0) { // turnCount를 3으로 나눈 나머지가 0이면 3의 배수
                    char userAnswer[100]; //돌발 퀘스트를 위한 사용자 입력
                    printf("\n*** 돌발 퀘스트 발생! ***\n");
                    printf("%s이의 털 색깔은 무엇일까요?\n", name);
                    printf(">> ");
                    scanf_s("%s", userAnswer, 100);
                    printf("틀렸습니다. 이곳에서 그 고양이는 실존하지 않습니다.\n 당신은 이 프로그램을 통해 상상을 만들어 내어 그 상상 속 고양이의 색깔을 말한 것 인가요?\n");
                    printf("살아있던 적도 죽었던 적도 없습니다.\n 하지만 당신의 머릿속에서는 살아있었을 수도 있었겠네요.\ 고양이도 이미 알고 있었을 것 입니다.\n %s는 어떤 모습이었나요?\n 웃고있었나요?\n\n", name);
                    printf("*** 돌발 퀘스트 종료 ***\n");
                    printf("\n");
                }
                Sleep(2000);
                system("cls");
            }

            return 0;
        }