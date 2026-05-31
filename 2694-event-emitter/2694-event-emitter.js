class EventEmitter {
    constructor(){
        this.events = new Map()
    }
    /**
     * @param {string} eventName
     * @param {Function} callback
     * @return {Object}
     */
    subscribe(eventName, callback) {
        if(!this.events.has(eventName)){
            this.events.set(eventName, [])
        }
        let listeners = this.events.get(eventName)
        listeners.push(callback)
        this.events.set(eventName, listeners)
        return {
            unsubscribe: () => {
                let listeners = this.events.get(eventName)
                let idx = listeners.indexOf(callback)
                if(idx !== -1){
                    listeners.splice(idx,1)
                }
                return undefined
            }
        };
    }
    
    /**
     * @param {string} eventName
     * @param {Array} args
     * @return {Array}
     */
    emit(eventName, args = []) {
        if(!this.events.has(eventName)){
            return []
        }
        let results = []
        let listeners = this.events.get(eventName)
        for(const listener of listeners) {
            results.push(listener(...args))
        }
        return results
    }
}

/**
 * const emitter = new EventEmitter();
 *
 * // Subscribe to the onClick event with onClickCallback
 * function onClickCallback() { return 99 }
 * const sub = emitter.subscribe('onClick', onClickCallback);
 *
 * emitter.emit('onClick'); // [99]
 * sub.unsubscribe(); // undefined
 * emitter.emit('onClick'); // []
 */