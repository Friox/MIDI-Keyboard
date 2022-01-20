#include <iostream>
#include <cstdlib>
#include <signal.h>
#include <windows.h>
#include "RtMidi.h"

bool done;
static void finish(int ignore) { done = true; }
void print(const char *s) { std::cout << s << "\n"; }

int main() {

    print("\nMIDI Keyboard");
    print("for DJMAX Respect V");
    print("");
    print("[키맵] # 건반이름(미디코드) : 키");
    print("F3(53) : L_Shift\tG3(55) : Z\tA3(57) : X\tB3(59) : C");
    print("F4(65) : ,\t\tG4(67) : .\tA4(69) : /\tB4(71) : R_Shift");
    print("");

    int key_id[19] = { 0 };
    key_id[0] = 0xA0;       // F3, L_Shift
    key_id[2] = 0x5A;       // G3, Z
    key_id[4] = 0x58;       // A3, X
    key_id[6] = 0x43;       // B3, C
    key_id[12] = 0xBC;      // F4, ,
    key_id[14] = 0xBE;      // G4, .
    key_id[16] = VK_OEM_2;  // A4, /
    key_id[18] = 0xA1;      // B4, R_Shift

    RtMidiIn* midiin = 0;
    unsigned int nPorts = 0;
    try {
        midiin = new RtMidiIn();
    } catch (RtMidiError) {
        std::cout << "[ERROR] 객체 생성실패 ㅠㅠ" << std::endl;
        system("pause");
        delete midiin;
        return 0;
    }
    nPorts = midiin->getPortCount();
    if (nPorts) {
        unsigned int portNum = 0;
        int logBool = 0;
        char logChar;
        std::cout << "[INFO] " << nPorts << " 개의 입력포트가 감지되었어요." << std::endl;
        std::string portName;
        for (unsigned int i = 0; i < nPorts; i++) {
            try {
                portName = midiin->getPortName(i);
            } catch (RtMidiError) {
                std::cout << "[ERROR] 포트정보를 가져오는 중 오류가 발생했어요 ㅠㅠ" << std::endl;
                system("pause");
                delete midiin;
                return 0;
            }
            std::cout << "입력포트 #" << i + 1 << " : " << portName.substr(0, portName.length() - 2) << '\n';
        }
        std::cout << "\n[INPUT] 포트 번호를 입력해주세요 : ";
        std::cin >> portNum;
        std::cout << "[INPUT] 로그를 볼래요? (눌린키 확인가능, 약간의 성능저하가 있어요) (y/N) : ";
        std::cin >> logChar;
        if (logChar == 'y' || logChar == 'Y') logBool = 1;
        if (portNum > 0 && portNum <= nPorts) {
            std::vector<unsigned char> message;
            midiin->openPort(portNum - 1);
            midiin->ignoreTypes(false, false, false);
            done = false;
            (void)signal(SIGINT, finish);
            std::cout << "[INFO] 미디데이터 변환중... 종료하려면 Ctrl-C.\n";
            while (!done) {
                midiin->getMessage(&message);
                if (message.size()) {
                    int key_code = (int)message[1] - 53;
                    int key_vel = (int)message[2];
                    if (key_code >= 0 && key_code <= 18) {
                        if (!key_vel) {
                            keybd_event(key_id[key_code], MapVirtualKey(key_id[key_code], 0), KEYEVENTF_KEYUP, 0);
                            if (logBool) std::cout << "[LOG] " << key_code + 53 << " >> " << key_id[key_code] << " [UP]" << std::endl;
                        } else {
                            keybd_event(key_id[key_code], MapVirtualKey(key_id[key_code], 0), 0, 0);
                            if (logBool) std::cout << "[LOG] " << key_code + 53 << " >> " << key_id[key_code] << " [DOWN]" << std::endl;
                        }     
                    }
                }
                Sleep(1);
            }
        }
    } else {
        print("[INFO] 감지된 입력포트가 없어요");
    }
    delete midiin;
    print("[INFO] 안전하게 종료했어요! (엔터를 누르면 창을닫습니다)");
    system("pause>nul");
    return 0;
}