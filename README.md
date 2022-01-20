# MIDI Keyboard
마스터키보드와 같은 MIDI 장비의 MIDI 신호를 키보드 입력으로 변환해줍니다.  
DJMAX Respect V에 최적화 되어있습니다.  
  
## 사용법
MIDI 장비를 연결한 후 프로그램을 실행합니다.  
인식된 장비가 없으면 작동하지 않습니다.  
장비를 선택한 후 변환을 시작합니다.  

가온 도(middle C)인 C4를 기준으로 합니다. (미디코드 60)  
|MIDI|KEY|MIDI|KEY|
|:-:|-|:-:|-|
|F3 (53)|L_Shift (0xA0)|F4 (65)|, (0xBC)|
|G3 (55)|Z (0x5A)|G4 (67)|. (0xBE)|
|A3 (57)|X (0x58)|A4 (69)|/ (0xBF, VK_OEM_2)|
|B3 (59)|C (0x43)|B4 (71)|R_Shift (0xA1)|

대응하는 키는 소스에서 자유롭게 수정가능합니다.  
프로그램을 실행시켜놓고 다른 작업을 하시면 됩니다.  

컴파일은 아래 RtMidi 홈페이지를 참고하시면 됩니다.  
RtMidi 라이브러리가 필요합니다.  
  
## 라이브러리
- RtMidi
  - 미디신호를 처리하는 라이브러리  
  - https://www.music.mcgill.ca/~gary/rtmidi/  
  - https://github.com/thestk/rtmidi  
  
## 참고
RtMidi : https://www.music.mcgill.ca/~gary/rtmidi/  
RtMidi(Github) : https://github.com/thestk/rtmidi  
Virtual-Key Code : https://docs.microsoft.com/ko-kr/windows/win32/inputdev/virtual-key-codes  
MIDI Number : https://newt.phys.unsw.edu.au/jw/notes.html  
  
## 라이센스
RtMidi: realtime MIDI i/o C++ classes  
Copyright (c) 2003-2019 Gary P. Scavone  
<BR>
Permission is hereby granted, free of charge, to any person  
obtaining a copy of this software and associated documentation files  
(the "Software"), to deal in the Software without restriction,  
including without limitation the rights to use, copy, modify, merge,  
publish, distribute, sublicense, and/or sell copies of the Software,  
and to permit persons to whom the Software is furnished to do so,  
subject to the following conditions:  
<BR>
The above copyright notice and this permission notice shall be  
included in all copies or substantial portions of the Software.  
<BR>
Any person wishing to distribute modifications to the Software is  
asked to send the modifications to the original developer so that  
they can be incorporated into the canonical version.  This is,  
however, not a binding provision of this license.  
<BR>
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  
IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR  
ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF  
CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION  
WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.  
