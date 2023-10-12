# BAND Open API Examples in C

C언어로 작성한 간단한 BAND Open API 테스트 예제입니다.

## Access Token 발급 받기

BAND Open API를 호출하기 위해서는 먼저 API 호출 권한에 해당하는 Access Token을 발급 받아야 합니다.

Access Token을 발급 받는 방법은 [여기][perl examples]에서 확인하실 수 있습니다.

## BAND Open API 테스트

### 의존성 설치

프로젝트를 빌드하기 위해서는 curl 라이브러리가 필요합니다.

대부분의 macOS 및 Linux 운영체제에는 curl 라이브러리가 기본적으로 설치되어 있습니다.

만약 curl 라이브러리가 설치되지 않은 경우 [여기][install curl]에 안내된 대로 설치를 진행하시면 됩니다.

### `parameters` 수정

프로젝트의 `main.c` 소스코드를 열어서 테스트하고자 하는 함수 내의 `parameters` 스트링을 적절하게 수정해줍니다.

테스트를 원하는 함수가 `get_profile()`이고, 발급 받은 Access Token이 `abcd`일 경우 아래와 같이 `parameters` 스트링을 수정해주시면 됩니다.

```c
void get_profile(void)
{
        const char *url = "https://openapi.band.us/v2/profile";
        const char *parameters = "access_token=abcd"; // 수정
        http_get(url, parameters)
}
```

### 빌드 및 실행

프로젝트 디렉터리로 이동 후 C 컴파일러로 curl 라이브러리를 링크하여 프로젝트를 빌드 및 실행합니다.

```bash
$ cc main.c -l curl -o bandopenapi && ./bandopenapi
```

## 참고

### 추가 작업

본 프로젝트의 예제는 C언어로 BAND Open API 호출하여 받은 응답을 콘솔에 출력해보는 매우 간단한 테스트 예제입니다.

그러나 테스트 목적을 넘어 BAND Open API와 원활하게 상호작용하는 실사용 목적의 C 프로그램 작성을 원할 경우 다음과 같은 추가 기능들이 필요할 수 있습니다.

- 주어진 파라미터를 이용해 `parameters` 스트링을 동적으로 생성하기
- HTTP 응답을 메모리에 할당받기
- HTTP 응답 코드를 처리하기
- HTTP 응답 바디를 파싱하기
- curl 예외를 처리하기

이 외에도 프로그램의 용도와 목적에 따라 다양한 추가 기능들이 필요할 수 있습니다.
프로그램에 필요한 기능들을 직접 C언어로 구현하여 BAND Open API를 이용하시면 됩니다.

각 기능의 구현을 도와주는 라이브러리의 도움을 받는 것도 좋은 방법입니다.
예를 들어 HTTP 응답 바디를 파싱하는 기능을 구현할 때는 [cJSON], [json-c]와 같은 C언어를 지원하는 JSON 라이브러리의 사용을 고려해볼 수 있습니다.
또 HTTP 응답을 메모리에 할당받거나 curl 예외를 처리할 때는 [curl][curl] 라이브러리가 제공하는 여러 세부 기능들을 이용해볼 수 있습니다.

### 관련 링크

- [BAND 개발자 페이지][BAND Developers]
- [다른 프로그래밍 언어로 작성한 예제][BAND Open API Examples in Other Languages]

[perl examples]: https://github.com/heetakchoi/bandopenapi#시작하기-전에
[install curl]: https://everything.curl.dev/get
[curl]: https://curl.se
[cjson]: https://github.com/DaveGamble/cJSON
[json-c]: https://github.com/json-c/json-c
[BAND Developers]: https://developers.band.us
[BAND Open API Examples in Other Languages]: https://developers.band.us/develop/guide/api/examples
