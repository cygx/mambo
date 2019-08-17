use NQPHLL;

grammar Mambo::Grammar is HLL::Grammar {
    token TOP {
        :my $*CUR_BLOCK := QAST::Block.new(QAST::Stmts.new());
        [ $ || <.panic('Syntax error')> ]
    }
}

class Mambo::Actions is HLL::Actions {}

class Mambo::Compiler is HLL::Compiler {}

sub MAIN(*@ARGS) {
    my $comp := Mambo::Compiler.new();
    $comp.language('mambo');
    $comp.parsegrammar(Mambo::Grammar);
    $comp.parseactions(Mambo::Actions);
    $comp.command_line(@ARGS, :encoding('utf8'));
}
