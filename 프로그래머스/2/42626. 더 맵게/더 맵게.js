class Heap {
    constructor(isMinHeap = true) {
        this.heap = [];
        this.compare = isMinHeap ? (a, b) => a - b : (a, b) => b - a;
    }
    
    swap(index1, index2) {
        [this.heap[index1], this.heap[index2]] = [this.heap[index2], this.heap[index1]];
    }
    
  	insert(value) {
        this.heap.push(value);
        this.bubbleUp();
    }
    bubbleUp() {
        let index = this.heap.length - 1;
        while(index > 0) {
            const parentIndex = Math.floor((index - 1) / 2);
            if(this.compare(this.heap[parentIndex], this.heap[index]) <= 0) break;
            this.swap(parentIndex, index);
            index = parentIndex;
        }
    }
    
  	remove() {
        if(this.heap.length === 0) return null;
        if(this.heap.length === 1) return this.heap.pop();
        
        const root = this.heap[0];
        this.heap[0] = this.heap.pop();
        this.bubbleDown();
        return root;
    }
    bubbleDown() {
        let index = 0;
        const length = this.heap.length;
        while(index * 2 + 1 < length) {
            let betterIndex = index * 2 + 1;
            const rightIndex = index * 2 + 2;
            if(rightIndex < length && this.compare(this.heap[rightIndex], this.heap[betterIndex]) < 0) {
                betterIndex = rightIndex;
            }
            if(this.compare(this.heap[index], this.heap[betterIndex]) <= 0) break;
            this.swap(index, betterIndex);
            index = betterIndex;
        }
    }
}

function solution(scoville, K) {
    let answer = 0;
    const minHeap = new Heap();
    
    scoville.forEach(sc => minHeap.insert(sc));
    
    while(minHeap.heap.some(sc => sc < K)) {
        const first = minHeap.remove();
        if(minHeap.heap.length === 0) {
            return -1;
        }
        const second = minHeap.remove();
        
        minHeap.insert(first + second*2);
        answer++;
    }
    
    return answer;
}