#define DECL_NOT_AVAILABLE(d) d {\
  panic("function not available on POSIX");\
  }

typedef void* agentclaim_t;
typedef void* constraints_t;
typedef int tile_id_t;
typedef int res_type_t;
typedef void* agent_t;

DECL_NOT_AVAILABLE(agentclaim_t agentclaim_get_current(void))
DECL_NOT_AVAILABLE(void agentclaim_set_current(agentclaim_t ac))
DECL_NOT_AVAILABLE(int agent_claim_get_pecount(agentclaim_t claim))
DECL_NOT_AVAILABLE(int agent_claim_get_pecount_tile_type(agentclaim_t claim, tile_id_t tileID, res_type_t type))
DECL_NOT_AVAILABLE(int agent_claim_get_tilecount(agentclaim_t claim))
DECL_NOT_AVAILABLE(int agent_claim_get_tileid_iterative(agentclaim_t claim, int iterator))
DECL_NOT_AVAILABLE(agentclaim_t agent_claim_invade(agent_t parentagent, constraints_t constr))
DECL_NOT_AVAILABLE(void agent_claim_print(agentclaim_t claim))
DECL_NOT_AVAILABLE(int agent_claim_reinvade(agentclaim_t claim))
DECL_NOT_AVAILABLE(int agent_claim_reinvade_constraints(agentclaim_t claim, constraints_t constr))
DECL_NOT_AVAILABLE(void agent_claim_retreat(agentclaim_t claim))
DECL_NOT_AVAILABLE(constraints_t agent_constr_create())
DECL_NOT_AVAILABLE(void agent_constr_overwrite(constraints_t constrTarget, constraints_t additionalConstraints))

