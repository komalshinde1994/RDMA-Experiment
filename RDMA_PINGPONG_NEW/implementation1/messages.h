#ifndef RDMA_MESSAGES_H
#define RDMA_MESSAGES_H

const char *DEFAULT_PORT = "12345";
const size_t BUFFER_SIZE = 28;

enum message_id
{
  MSG_INVALID = 0,
  MSG_MR,
  MSG_READY,
  MSG_DONE
};

struct message
{
  int id;
  char *buffer;
  struct ibv_mr *buffer_mr;

  union
  {
    struct
    {
      uint64_t addr;
      uint32_t rkey;
    } mr;
  } data;
};

#endif