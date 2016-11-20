#include "redismodule.h"
#include "rmutil/util.h"
#include "rmutil/strings.h"
#include "rmutil/test_util.h"
#include <stdlib.h>
#include <string.h>
int CommentCommand(RedisModuleCtx *ctx, RedisModuleString **argv, int argc)
{
    RedisModule_ReplyWithSimpleString(ctx, "OK");
    return REDISMODULE_OK;    
}

int RedisModule_OnLoad(RedisModuleCtx *ctx)
{
    // Register the module itself
    if (RedisModule_Init(ctx, "COMMENTDIS", 1, REDISMODULE_APIVER_1) ==
      REDISMODULE_ERR) {
        return REDISMODULE_ERR;
    }

    // register CommentCommand - using the shortened utility registration macro
    RMUtil_RegisterWriteCmd(ctx, "#", CommentCommand);

    // register CommentCommand - using the shortened utility registration macro
    RMUtil_RegisterWriteCmd(ctx, ";;", CommentCommand);

    // register CommentCommand - using the shortened utility registration macro
    RMUtil_RegisterWriteCmd(ctx, "//", CommentCommand);

    // register CommentCommand - using the shortened utility registration macro
    RMUtil_RegisterWriteCmd(ctx, "/*", CommentCommand);

    // register CommentCommand - using the shortened utility registration macro
    RMUtil_RegisterWriteCmd(ctx, "/**", CommentCommand);

    // register CommentCommand - using the shortened utility registration macro
    RMUtil_RegisterWriteCmd(ctx, "comment", CommentCommand);

    // register CommentCommand - using the shortened utility registration macro
    RMUtil_RegisterWriteCmd(ctx, "comment:", CommentCommand);


    return REDISMODULE_OK;
}