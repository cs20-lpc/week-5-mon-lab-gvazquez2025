template <typename T>
typename DoublyList<T>::Node* DoublyList<T>::getNode(int position) const {
    if (position < 0 || position >= this->length) {
        throw string("getNode: error, position out of bounds");
    }
    Node* curr = header->next;
    for (int i = 0; i < position; i++) {
        curr = curr->next;
    }
    return curr;
}

template <typename T>
void DoublyList<T>::append(const T& elem) {
    Node* n = new Node(elem, trailer, trailer->prev);
    trailer->prev->next = n;
    trailer->prev = n;
    this->length++;
}

template <typename T>
T DoublyList<T>::getElement(int position) const {
    return getNode(position)->value;
}

template <typename T>
void DoublyList<T>::insert(int position, const T& elem) {
    if (position < 0 || position > this->length) {
        throw string("insert: error, position out of bounds");
    }
    Node* succ = (position == this->length) ? trailer : getNode(position);
    Node* pred = succ->prev;
    Node* n = new Node(elem, succ, pred);
    pred->next = n;
    succ->prev = n;
    this->length++;
}

template <typename T>
void DoublyList<T>::remove(int position) {
    Node* target = getNode(position);
    Node* pred = target->prev;
    Node* succ = target->next;
    pred->next = succ;
    succ->prev = pred;
    delete target;
    this->length--;
}

template <typename T>
bool DoublyList<T>::search(const T& elem) const {
    Node* curr = header->next;
    while (curr != trailer) {
        if (curr->value == elem) {
            return true;
        }
        curr = curr->next;
    }
    return false;
}

template <typename T>
void DoublyList<T>::replace(int position, const T& elem) {
    getNode(position)->value = elem;
}
