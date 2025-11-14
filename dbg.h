#include <bits/stdc++.h>
using namespace std;

#define fast_io()                                                              \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL)

#define dbg_test_fun

static uint16_t dbg_test_no = 0;

// clang-format off
#define dbg_ansi_reset      "\033[0m"
#define dbg_ansi_red        "\033[31m"
#define dbg_ansi_green      "\033[32m"
#define dbg_ansi_yellow     "\033[33m"
#define dbg_ansi_gray       "\033[90m"
#define dbg_tab             << "\t" <<
#define dbg_newline         << "\n" <<

#define dbg_var(var)        cout << #var << ": " << var << endl
#define dbg_var_t(var)      cout << #var << ": " << var << "\t" << flush
#define dbg_nl()            cout << endl

#define dbg_print(...)      cout << __VA_ARGS__ << flush
#define dbg_println(...)    cout << __VA_ARGS__ << endl
#define dbg_cprint(...)     printf(__VA_ARGS__); fflush(stdout)
// clang-format on

#define dbg_cprintln(...)                                                      \
  do {                                                                         \
    printf(__VA_ARGS__);                                                       \
    printf("\n");                                                              \
  } while (0)
#define dbg_print_each(list)                                                   \
  do {                                                                         \
    for (auto listItem : list) {                                               \
      dbg_print(listItem << ", ");                                             \
    }                                                                          \
    dbg_nl();                                                                  \
  } while (0)
#define dbg_text(color, ...)                                                   \
  do {                                                                         \
    printf(color);                                                             \
    dbg_cprint(__VA_ARGS__);                                                   \
    printf(dbg_ansi_reset);                                                    \
  } while (0)

#define dbg_error(...) cerr << __VA_ARGS__ << "\n"
#define dbg_panic(...)                                                         \
  do {                                                                         \
    cerr << __VA_ARGS__ << "\n";                                               \
    exit(EXIT_FAILURE);                                                        \
  } while (0)
#define dbg_cerror(...)                                                        \
  do {                                                                         \
    fprintf(stderr, __VA_ARGS__);                                              \
    fprintf(stderr, "\n");                                                     \
  } while (0)
#define dbg_cpanic(...)                                                        \
  do {                                                                         \
    fprintf(stderr, __VA_ARGS__);                                              \
    fprintf(stderr, "\n");                                                     \
    exit(EXIT_FAILURE);                                                        \
  } while (0)

#define dbg_depict_error(val, dbg_test_ret_val)                                \
  do {                                                                         \
    dbg_error("Expected → " << val);                                           \
    dbg_error("Got      → " << dbg_test_ret_val);                              \
  } while (0)

#ifdef dbg_expect_1DV
#undef dbg_depict_error
#define dbg_depict_error(val, dbg_test_ret_val)                                \
  do {                                                                         \
    dbg_error("Expected →");                                                   \
    dbg_print_each(val);                                                       \
    dbg_error("Got      →");                                                   \
    dbg_print_each(dbg_test_ret_val);                                          \
  } while (0)
#endif

#ifdef dbg_expect_2DV
#undef dbg_depict_error
#define dbg_depict_error(val, dbg_test_ret_val)                                \
  do {                                                                         \
    dbg_error("Expected →");                                                   \
    for (auto &each_val : val) {                                               \
      dbg_print_each(each_val);                                                \
    }                                                                          \
    dbg_error("Got      →");                                                   \
    for (auto &test_val : dbg_test_ret_val) {                                  \
      dbg_print_each(test_val);                                                \
    }                                                                          \
  } while (0)
#endif

#define dbg_test(val)                                                          \
  do {                                                                         \
    dbg_text(dbg_ansi_yellow, "┍━┫ TEST %d ▛▟\n", dbg_test_no++);              \
    chrono::time_point dbg_time_begin = chrono::steady_clock::now();           \
    auto dbg_test_ret_val = dbg_test_fun;                                      \
    chrono::time_point dbg_time_end = chrono::steady_clock::now();             \
    chrono::nanoseconds diff = chrono::duration_cast<chrono::nanoseconds>(     \
        dbg_time_end - dbg_time_begin);                                        \
    dbg_print("┊");                                                            \
    dbg_text(dbg_ansi_gray, " ┊ %d ns(10^-9)\n", diff.count());                \
    if (dbg_test_ret_val == val) {                                             \
      dbg_text(dbg_ansi_green, "╰─ Passed\n");                                 \
    } else {                                                                   \
      dbg_text(dbg_ansi_red, "Failed\n");                                      \
      dbg_depict_error(val, dbg_test_ret_val);                                 \
    }                                                                          \
    dbg_nl();                                                                  \
  } while (0)
#define dbg_test_with(val, ...)                                                \
  do {                                                                         \
    __VA_ARGS__;                                                               \
    dbg_test(val);                                                             \
  } while (0)
