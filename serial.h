
#include <termios.h>
#include <unistd.h>

class SerialPort{
public:
  SerialPort();
  virtual ~SerialPort();
  bool openPort(const char* device, int baudrate);
  void closePort();
  int putChar(unsigned char c);
  int putBytes(const unsigned char* bytes, int num);
  bool getChar(unsigned char* c);
  int getBytes(unsigned char* bytes, int num);
private:
  struct termios m_oldTio;
  int m_fd;
  struct timeval m_timeout;
  fd_set m_readfs;
};