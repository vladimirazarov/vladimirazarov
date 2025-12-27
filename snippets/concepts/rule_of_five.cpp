class BufferManager {
 public:
  explicit BufferManager(size_t size) : size_(size), data_(new int[size]) {}

  // 1. DESTRUCTOR
  ~BufferManager() { delete[] data_; }

  // 2. COPY CONSTRUCTOR (Deep Copy)
  // Triggered by: BufferManager b2 = b1;
  BufferManager(const BufferManager& other) : size_(other.size_) {
    data_ = new int[size_]; 
    std::copy(other.data_, other.data_ + size_, data_);
    std::cout << "Deep Copy performed!\n";
  }

  // 3. COPY ASSIGNMENT
  // Triggered by: b2 = b1; (where both already exist)
  BufferManager& operator=(const BufferManager& other) {
    if (this == &other) return *this; // Self-assignment check
    delete[] data_; // Clean up our old memory first!
    size_ = other.size_;
    data_ = new int[size_];
    std::copy(other.data_, other.data_ + size_, data_);
    return *this;
  }

  // 4. MOVE CONSTRUCTOR (The "Steal")
  // Triggered by: BufferManager b2 = std::move(b1);
  BufferManager(BufferManager&& other) noexcept 
      : data_(other.data_), size_(other.size_) {
    other.data_ = nullptr; // Leave the other object empty
    other.size_ = 0;
    std::cout << "Move: Pointer stolen!\n";
  }

  // 5. MOVE ASSIGNMENT
  BufferManager& operator=(BufferManager&& other) noexcept {
    if (this == &other) return *this;
    delete[] data_;
    data_ = other.data_;
    size_ = other.size_;
    other.data_ = nullptr;
    other.size_ = 0;
    return *this;
  }

 private:
  int* data_;
  size_t size_;
};