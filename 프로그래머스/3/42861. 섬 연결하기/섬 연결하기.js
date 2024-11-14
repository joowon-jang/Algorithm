class Heap {
    // 최소, 최대 Heap 구분
    constructor(isMinHeap = true) {
        this.heap = [];
        // Heap의 종류에 따라 다른 비교 연산
        this.compare = isMinHeap ? (a, b) => a[1] - b[1] : (a, b) => b[1] - a[1];
    }
    
    // 노드 교환
    swap(index1, index2) {
        [this.heap[index1], this.heap[index2]] = [this.heap[index2], this.heap[index1]];
    }
    
  	// 데이터 삽입
  	insert(value) {
        this.heap.push(value);
      	// 데이터 삽입 후 Heap 규칙에 맞게 정리
        this.bubbleUp();
    }
    bubbleUp() {
      	// 트리 끝의 노드
        let index = this.heap.length - 1;
        while(index > 0) {
          	// 비교할 부모 노드
            const parentIndex = Math.floor((index - 1) / 2);
            // 현재 노드의 값이 부모 노드의 값보다 크면(최대힙은 작으면) 끝
            if(this.compare(this.heap[parentIndex], this.heap[index]) <= 0) break;
            // 규칙에 맞지 않으면 두 노드를 교환
            this.swap(parentIndex, index);
          	// 다음 bubbleUp연산을 위해 교환한 자리의 index를 할당
            index = parentIndex;
        }
    }
    
    // 데이터 삭제
  	remove() {
      	// 트리가 비어있으면 null 반환
        if(this.heap.length === 0) return null;
      	// 트리에 노드가 하나이면 바로 삭제 및 반환
        if(this.heap.length === 1) return this.heap.pop();
        
        const root = this.heap[0];
      	// 트리 가장 끝의 노드를 루트로 이동
        this.heap[0] = this.heap.pop();
      	// 이동 후 Heap 규칙에 맞게 정리
        this.bubbleDown();
      	// 삭제한 데이터 반환
        return root;
    }
    bubbleDown() {
      	// 루트(로 이동한) 노드
        let index = 0;
        const length = this.heap.length;
      	// 노드가 리프로 갈 때까지 반복
        while(index * 2 + 1 < length) {
            let betterIndex = index * 2 + 1;
            const rightIndex = index * 2 + 2;
          	// 오른쪽 자식이 존재할 때, 양쪽 자식 노드 중 작은(최대 힙은 큰) 값을 선택
            if(rightIndex < length && this.compare(this.heap[rightIndex], this.heap[betterIndex]) < 0) {
                betterIndex = rightIndex;
            }
            // 현재 노드의 값이 자식 노드의 값보다 작으면(최대 힙은 크면) 끝
            if(this.compare(this.heap[index], this.heap[betterIndex]) <= 0) break;
            // 규칙에 맞지 않으면 두 노드를 교환
            this.swap(index, betterIndex);
          	// 다음 bubbleDown연산을 위해 교환한 자리의 index를 할당
            index = betterIndex;
        }
    }
}

function solution(n, costs) {
    let answer = 0;
    
    const graph = Array.from({ length: n }, () => []);
    for (const [u, v, w] of costs) {
        graph[u].push([v, w]);
        graph[v].push([u, w]);
    }
    
    const minHeap = new Heap();
    minHeap.insert([0, 0]);
    const visited = Array.from({ length : n }, () => false);
    
    while(minHeap.heap.length > 0) {
        const [u, cost] = minHeap.remove();
        if(visited[u]) continue;
        visited[u] = true;
        answer += cost;

        for(const [v, w] of graph[u]) {
            if(!visited[v]) minHeap.insert([v, w]);
        }
    }
    
    
    return answer;
}