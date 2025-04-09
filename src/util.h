#define MAKE_SINGLETON(classname)                                              \
public:                                                                        \
  static classname &get() {                                                    \
    static classname s_instance;                                               \
    return s_instance;                                                         \
  }                                                                            \
                                                                               \
private:  \
  classname();                                                                     \
  classname &operator=(const classname &) = delete;                            \
  classname(const classname &) = delete;