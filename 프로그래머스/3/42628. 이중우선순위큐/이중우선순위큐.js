class Heap {
    constructor(isMinHeap = true) {
        this.heap = [];
        this.compare = isMinHeap ? (a, b) => a - b : (a, b) => b - a;
    }
    
    swap(index1, index2) {
        [this.heap[index1], this.heap[index2]] = [this.heap[index2], this.heap[index1]];
    }
    
    // insert 연산
    bubbleUp() {
        let index = this.heap.length - 1;
        while(index > 0) {
            const parentIndex = Math.floor((index - 1) / 2);
            
            if(this.compare(this.heap[parentIndex], this.heap[index]) <= 0) break;
            
            this.swap(parentIndex, index);
            index = parentIndex;
        }
    }
    insert(value) {
        this.heap.push(value);
        this.bubbleUp();
    }
    
    // remove 연산
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
    remove() {
        if(this.heap.length === 0) return null;
        if(this.heap.length === 1) return this.heap.pop();
        
        const root = this.heap[0];
        this.heap[0] = this.heap.pop();
        this.bubbleDown();
        return root;
    }
}

function solution(operations) {
    let answer = [];
    const minHeap = new Heap(true);
    const maxHeap = new Heap(false);
    
    for(const operation of operations) {
        const [op, num] = operation.split(" ");
        
        switch(op) {
            case 'I': 
                minHeap.insert(Number(num));
                maxHeap.insert(Number(num));
            break;
            case 'D':
                if(num == -1) {
                    const top = minHeap.remove();
                    maxHeap.heap = maxHeap.heap.filter(node => node !== top);
                }
                if(num == 1) {
                    const top = maxHeap.remove();
                    minHeap.heap = minHeap.heap.filter(node => node !== top);
                }
            break;
        }
    }
    
    answer = [maxHeap.heap[0], minHeap.heap[0]];
    console.log(maxHeap, minHeap);
    if(!answer[0]) answer[0] = 0;
    if(!answer[1]) answer[1] = 0;
    
    return answer;
}