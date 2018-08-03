

cleos create account eosio eosbay EOS7ckzf4BMgxjgNSYV22rtTXga8R9Z4XWVhYp8TBgnBi2cErJ2hn EOS7ckzf4BMgxjgNSYV22rtTXga8R9Z4XWVhYp8TBgnBi2cErJ2hn
cleos create account eosio buyer EOS7ckzf4BMgxjgNSYV22rtTXga8R9Z4XWVhYp8TBgnBi2cErJ2hn EOS7ckzf4BMgxjgNSYV22rtTXga8R9Z4XWVhYp8TBgnBi2cErJ2hn
cleos create account eosio seller EOS7ckzf4BMgxjgNSYV22rtTXga8R9Z4XWVhYp8TBgnBi2cErJ2hn EOS7ckzf4BMgxjgNSYV22rtTXga8R9Z4XWVhYp8TBgnBi2cErJ2hn

cleos create account eosio forsale1 EOS7ckzf4BMgxjgNSYV22rtTXga8R9Z4XWVhYp8TBgnBi2cErJ2hn EOS7ckzf4BMgxjgNSYV22rtTXga8R9Z4XWVhYp8TBgnBi2cErJ2hn
cleos create account eosio forsale2 EOS7ckzf4BMgxjgNSYV22rtTXga8R9Z4XWVhYp8TBgnBi2cErJ2hn EOS7ckzf4BMgxjgNSYV22rtTXga8R9Z4XWVhYp8TBgnBi2cErJ2hn



eosiocpp -o /eosdev/eosbay/eosbay.wast /eosdev/eosbay/eosbay.cpp && eosiocpp -g /eosdev/eosbay/eosbay.abi /eosdev/eosbay/eosbay.hpp && cleos set contract eosbay /eosdev/eosbay

cleos push action eosbay addlisting '["seller", "forsale1", "100.0000 EOS"]' -p seller
cleos push action eosbay addlisting '["seller", "forsale2", "1000.0000 EOS"]' -p seller

cleos push action eosbay addbid '["buyer", 0, "50.0000 EOS"]' -p buyer
cleos push action eosbay addbid '["buyer", 0, "50.0000 EOS"]' -p buyer