#include <stdio.h>
#include <stdlib.h>

// 비교 함수: 오름차순 정렬
int compare(const void *a, const void *b) {
  return *(int *)a - *(int *)b;
}

int main(void) {
  int n;
  scanf("%d", &n);

  // 입력 배열 생성
  int *value = malloc(n * sizeof(int));
  int *sorted = malloc(n * sizeof(int));
  for (int i = 0; i < n; i++) {
      scanf("%d", &value[i]);
      sorted[i] = value[i]; // 복사본 생성
  }

  // 정렬 수행 및 중복 제거 준비
  qsort(sorted, n, sizeof(int), compare);

  // 중복 제거: unique 배열 생성
  int unique_count = 0;
  int *unique = malloc(n * sizeof(int));
  unique[unique_count++] = sorted[0];
  for (int i = 1; i < n; i++) {
      if (sorted[i] != sorted[i - 1]) {
          unique[unique_count++] = sorted[i];
      }
  }

  // 좌표 압축 결과 출력
  for (int i = 0; i < n; i++) {
      // 이진 탐색으로 좌표 압축 계산
      int low = 0, high = unique_count - 1;
      while (low <= high) {
          int mid = (low + high) / 2;
          if (unique[mid] == value[i]) {
              printf("%d ", mid);
              break;
          } else if (unique[mid] < value[i]) {
              low = mid + 1;
          } else {
              high = mid - 1;
          }
      }
  }
  printf("\n");

  // 메모리 해제
  free(value);
  free(sorted);
  free(unique);

  return 0;
}